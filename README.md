# DC-Motors-Control-Project-with-L293D-Servo-Motor-and-Ultrasonic-Sensor
DC Motors Control Project with L293D, Servo Motor, and Ultrasonic Sensor
🚀 DC Motors Control Project with L293D, Servo Motor, and Ultrasonic Sensor
📌 Project Overview
This project focuses on controlling 4 DC motors and 1 Servo motor using the L293D motor driver shield and an Ultrasonic sensor. The goal is to program specific movement patterns and implement obstacle detection with automatic direction changes.
🛠️ Features
1️⃣ DC Motor Control
•	Forward: Runs for 30 seconds.
•	Backward: Runs for 1 minute.
•	Left & Right Rotation: Alternates direction for 1 minute.
2️⃣ Servo Motor Integration
•	Connect 1 servo motor to the L293D shield.
•	Attach an Ultrasonic sensor for obstacle detection.
•	If an obstacle is detected within 10 cm, the motors stop automatically and change direction.
🔧 Hardware Requirements
•	Arduino Uno board
•	L293D Motor Driver Shield
•	4 × DC Motors
•	1 × Servo Motor
•	Ultrasonic Sensor (HC-SR04 or similar)
•	Jumper wires and power supply

🧑‍💻 Software Requirements
•	Arduino IDE
•	Required Libraries:
o	Servo.h for servo motor control
o	NewPing.h or similar for ultrasonic sensor
⚙️ Setup Instructions
1.	Connect the 4 DC motors to the L293D motor driver according to pin configuration.
2.	Attach the servo motor to the shield’s servo pins.
3.	Wire the ultrasonic sensor to appropriate trigger and echo pins.
4.	Upload the Arduino code to implement:
o	Motor movement sequences
o	Obstacle detection
o	Automatic stop and direction change

🧪 Testing
•	Run the uploaded code and observe:
o	Forward, backward, left, and right movements.
o	Servo motor activation.
o	Automatic stop and reroute when an obstacle is detected within 10 cm.

✅ Deliverables
•	Complete Arduino code for motor and sensor control.
•	Circuit diagram showing all connections.
•	Demo video or live test results.

