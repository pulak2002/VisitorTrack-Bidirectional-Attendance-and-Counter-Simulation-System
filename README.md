# Bidirectional-Attendance-System-with-visitor-Counter-Simulation
A simulation of the attendance system based on the Aurdino UNO microcontroller was made using Tinker cad. The system reduced false attendance. It can count the number of students/employees in the hall/classroom and record their presence during a session. It shows movement type and student count.
Our objective is to design an attendance system with a live bidirectional visitor counter that can help people reduce their time on taking attendance manually. When someone enters the room, our model should be able to detect ID number when ID of the student is swiped and attendance for that student should be marked, simultaneously visitor counter increments when they enter. It should provide the number of attendees present in the class/meeting at any point in time. And our model should provide attendance whose ID number can be validated with the database/memory of the microcontroller. The integration of both the models should provide accurate attendance marking system
Our model can be used in classrooms to provide attendance to the students and also this would help in avoiding the bunking of classes. Our model can also be used to indicate number of people attending a private party where authentication is required. Even for official meetings in a company or any gatherings that requires identification, this model would help in identifying who all are in the meeting with total count of the number of people in it. This model even can be applied to home automation in a way like when no ones in the room switching off appliances to conserve energy.
Our model consists of 2 PIR sensors that would be detecting the movement near the entrance and would increment/decrement the count 7 of number of attendees in the room accordingly. RFID reader is used in our model to identify the person entering the room through the ID number provided to him/her through an ID card which is swiped on the RFID reader. Then RFID sends this ID number to microcontroller to process the attendance.

# Circuit Diagram:
![image](https://github.com/pulak2002/Bidirectional-Attendance-System-with-visitor-Counter-Simulation/assets/110912267/ad5ac3de-7de9-4e21-a5c8-eaf6eaf854cb)

# Components:
![image](https://github.com/pulak2002/Bidirectional-Attendance-System-with-visitor-Counter-Simulation/assets/110912267/a6f44559-f907-47c3-8bde-4f7faa4e1725)

# Simulation Structure
![image](https://github.com/pulak2002/Bidirectional-Attendance-System-with-visitor-Counter-Simulation/assets/110912267/84785be6-ee45-44ba-8fc7-b3c371c033d7)

Link: https://www.tinkercad.com/things/6i6wSkf03Cl?sharecode=3BYWAKBPTSS91qqCuX0dG19fJcAfxYNDj_as7-qvtRA
