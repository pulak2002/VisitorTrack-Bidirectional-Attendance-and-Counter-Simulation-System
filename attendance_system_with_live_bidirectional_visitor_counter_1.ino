#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(5, 4, 3, 2, A4, A5);
LiquidCrystal lcd1(8, 9, 10, 11, 12, 13);
struct student_detail{
  char name[6];
  char regno[10];
  int status;
};
char reg_no[9];
 int PIR1_PIN = 7;
 int PIR2_PIN = 6;
const bool SERIAL_PRINT = true;
int visitors = 0;
int lastRIPdetected = 0;
bool b_PIR1_active = false;
bool b_PIR2_active = false;
student_detail student_registered[10];
void DisplayMsg(String s1, String s2, bool ab_serial_print)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s1);
  lcd.setCursor(0, 1);  
  lcd.print(s2);
  delay(10000);
} 
// -------- Increase/Decrease visitors ---------
void UpdateVisitorsCounter(int x)
{ 
   int duration=100;
  visitors = visitors + x;
  lastRIPdetected = 0;  // reset detected PIR
}
void print()
{
       lcd1.clear();
    lcd1.setCursor(0,0);
     lcd1.print("Entry Processing");
}
void pir1()
{  
 
    { 
            if ( !b_PIR1_active ) 
            {
                b_PIR1_active = true;
      
                    if (lastRIPdetected == 0 && !b_PIR2_active) 
                     {  // new start
                        lastRIPdetected = 1;
                       print();
                         DisplayMsg("In PIR1", "Visit started", SERIAL_PRINT);
						return;
                      }
                     else if (lastRIPdetected == 2) 
                    { // if we were in PIR2 before
                        UpdateVisitorsCounter(-1);  
                        print();
                         DisplayMsg("Visitor exited", " " , SERIAL_PRINT);
                         return;
                     } 
             }
           }


}   
void pir2()
{
		  
                {
            lcd1.clear();
                    if ( !b_PIR2_active )
                        {
                             b_PIR2_active = true;
                             if (lastRIPdetected == 0 && !b_PIR1_active) 
                                 { // new start
                                     if (visitors > 0) 
                                            {
                                                lastRIPdetected = 2;
                                                 print();
                                                DisplayMsg("In PIR2", "Exit started", SERIAL_PRINT);
                                                return;
                                            } 
                                     else 
                                     { DisplayMsg("No more visitors", "to exit", SERIAL_PRINT);
                                      return;}
                                  } 
                             else if (lastRIPdetected == 1) 
                                  {  // if we were in PIR1 before
                                      UpdateVisitorsCounter(1);      
									print();
                                      DisplayMsg("Visitor entered", "  " , SERIAL_PRINT);
                                     return;
                                  }
                         }
                 }  

                
}

void student_registered_database()
{

  student_registered[0]={{'R','a','m',' ',' ',' '},{'2','0','B','R','S','0','0','0','0'},0};
  student_registered[1]={{'R','e','n',' ',' ',' '},{'2','0','B','R','S','0','0','0','1'},0};
  student_registered[2]={{'A','n','n','a',' ',' '},{'2','0','B','R','S','0','0','0','2'},0};
  student_registered[3]={{'A','R','A','Y','A','N'},{'2','0','B','R','S','0','0','0','3'},0};
  student_registered[4]={{'R','i','y','a',' ',' '},{'2','0','B','R','S','0','0','0','4'},0};
  student_registered[5]={{'M','a','n','n',' ',' '},{'2','0','B','R','S','0','0','0','5'},0};
  student_registered[6]={{'S','a','t','y','a','m'},{'2','0','B','R','S','0','0','0','6'},0};
  student_registered[7]={{'R','o','h','a','n',' '},{'2','0','B','R','S','0','0','0','7'},0};
  student_registered[8]={{'S','e','e','m','a',' '},{'2','0','B','R','S','0','0','0','8'},0};
  student_registered[9]={{'A','y','u','s','h',' '},{'2','0','B','R','S','0','0','0','9'},0};
}
int find()
{
  int status=-1;
  for(int i=0;i<10;i++)
  {
        if(reg_no[0]==student_registered[i].regno[0] && reg_no[1]==student_registered[i].regno[1] && reg_no[2]==student_registered[i].regno[2] && reg_no[3]==student_registered[i].regno[3] && reg_no[4]==student_registered[i].regno[4] && reg_no[5]==student_registered[i].regno[5] && reg_no[6]==student_registered[i].regno[6] && reg_no[7]==student_registered[i].regno[7] && reg_no[8]==student_registered[i].regno[8])
      {
      status=i;
      return status;
      break;
    }
  }
  return status;
}

int leave()
{
      int count=0;
        for(int i=0;i<10;i++)
    {
    if(student_registered[i].status==1)
    {
      count++;
    }
    }
  return count;
}
int no_of_present()
{
  int count=0;
  int stud[10];
  for(int i=0;i<10;i++)
  {
    if(student_registered[i].status==1)
    {
      stud[i]=student_registered[i].status;
      count++;
    }
  }
  return count;
}
void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(0,0);
   lcd1.begin(16, 2);
  //lcd1.setCursor(0,0);
  // lcd1.print("00");
  pinMode(PIR1_PIN, INPUT);
  pinMode(PIR2_PIN, INPUT);
  student_registered_database();
  
}
void loop()
{ 
    int stat=-1;
  if(Serial.available()>0)
  { lcd.clear();
      for(int i=0;i<9;i++)
             {
                  reg_no[i]=Serial.read();
            }
    Serial.print("Scanned Reg. no : ");
          for(int i=0;i<9;i++)
             {
                  Serial.print(reg_no[i]);
            }
    Serial.println(" ");
    stat=find();
    if(stat>=0)
    {
      if(student_registered[stat].status==1)
      {
            
        lcd.clear();
        for(int i=0;i<6;i++)
             {
                  lcd.setCursor(i,0);
                	lcd.print(student_registered[stat].name[i]);
            }
        lcd.print(" ");
         lcd.setCursor(7,1);
        int l=7;
        for(int i=0;i<9;i++)
            {
                lcd.setCursor(l++,0);
      	        lcd.print(student_registered[stat].regno[i]);
            }
         student_registered[stat].status=0;
        lcd.setCursor(0,1);
        lcd.print("Present = ");
         //lcd.print(a-1);
        int z=leave();
         lcd.print(z);
         lcd.print("(Out) ");
         delay(5000);
      
    }
    else
      {
       lcd.clear();
       for(int i=0;i<6;i++)
        {
            lcd.setCursor(i,0);
      	    lcd.print(student_registered[stat].name[i]);
        }
        lcd.print(" ");
        lcd.setCursor(7,1);
        int l=7;
        for(int i=0;i<9;i++)
             {
                 lcd.setCursor(l++,0);
                	lcd.print(student_registered[stat].regno[i]);
            }
        student_registered[stat].status=1;
        lcd.setCursor(0,1);
        lcd.print("Present = ");
        int z=no_of_present();
        lcd.print(z);
        lcd.print(" (In) ");
        delay(10000);
      }
        
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Unregistered");
      lcd.setCursor(0,1);
      lcd.print("Present = ");
      int z=no_of_present();
      lcd.print(z);
      delay(10000);
    }
  }
  else
  {  
    lcd1.clear();
    lcd1.print("Live Counter");
    lcd1.setCursor(0,1);
    lcd1.print("Visitors: ");
    lcd1.print(visitors);
    if(digitalRead(PIR1_PIN)==HIGH)
    {	

      pir1();
    }
    else 
      b_PIR1_active = false ;  // reenable PIR1
    if(digitalRead(PIR2_PIN)==HIGH)
    {

      pir2();
    }
	else 
       b_PIR2_active = false; // reenable PIR2

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tap your Card");
    lcd.setCursor(0,1);
    lcd.print("Present = ");
    int z=no_of_present();
    lcd.print(z);
    delay(5000);
}


}
