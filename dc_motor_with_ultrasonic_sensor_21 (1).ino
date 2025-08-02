//The Servo motor shows the movement of HC-SR04 in real life(as it cannot be done in tinkercad).
//forward high pins = {dir1 , dir4 , dir5 , dir8}
//backward high pins = {dir2 , dir3 , dir6 , dir7}
#include <Servo.h>
Servo myservo;
int servopin=A5;
int trigpin=A1;
int echopin=A0;
int speedpin1=3;  //back right 
int dir1=5;
int dir2=7;
int speedpin2=6;  //front right 
int dir3=8;
int dir4=10;
int speedpin3=9;  //back left
int dir5=2;
int dir6=4;
int speedpin4=11; //front left
int dir7=12;
int dir8=13;
void setup()
{
  Serial.begin(9600);
  myservo.attach(servopin);
  myservo.write(90);
  delay(3000);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(speedpin1, OUTPUT);
  pinMode(speedpin2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(speedpin3, OUTPUT);
  pinMode(speedpin4, OUTPUT);
  pinMode(dir5, OUTPUT);
  pinMode(dir6, OUTPUT);
  pinMode(dir7, OUTPUT);
  pinMode(dir8, OUTPUT);
}

float duration;

void loop() 
{
  // put your main code here, to run repeatedly:
  
  ping();
  duration=pulseIn(echopin,HIGH); 
  Serial.print("Forward distance = ");
  Serial.println(duration);
  delay(100);
  if(duration<=5500.00)
  {
    Serial.println("Object ditected");
    Stop();
    delay(1000);
      back();
      delay(1500);
      Stop();
      delay(1000);
      leftD();
      delay(1000);
      rightD();
      delay(1000);
      if(rightD()<leftD())
      {
        turnleft();
      }
      else
    {
        turnright();
      }
    }
  else
  {
      forward();
  }
    
}
int Stop()
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
  digitalWrite(dir5,LOW);
  digitalWrite(dir6,LOW);
  digitalWrite(dir7,LOW);
  digitalWrite(dir8,LOW);
  analogWrite(speedpin1,0);
  analogWrite(speedpin2,0);
  analogWrite(speedpin3,0);
  analogWrite(speedpin4,0);
}
int forward()
{
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(speedpin1,255);
  delay(25);					 
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  analogWrite(speedpin2,255);
  delay(25);					
  digitalWrite(dir5,HIGH);
  digitalWrite(dir6,LOW);
  analogWrite(speedpin3,255);
  delay(25);					
  digitalWrite(dir7,LOW);
  digitalWrite(dir8,HIGH);
  analogWrite(speedpin4,255);
}
int back()
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  analogWrite(speedpin1,255);
  delay(25);					 
  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,LOW);
  analogWrite(speedpin2,255);
  delay(25);					
  digitalWrite(dir5,LOW);
  digitalWrite(dir6,HIGH);
  analogWrite(speedpin3,255);
  delay(25);					
  digitalWrite(dir7,HIGH);
  digitalWrite(dir8,LOW);
  analogWrite(speedpin4,255);
}
int turnright()
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
  digitalWrite(dir5,HIGH);
  digitalWrite(dir6,LOW);
  digitalWrite(dir7,LOW);
  digitalWrite(dir8,HIGH);
  analogWrite(speedpin1,0);
  analogWrite(speedpin2,0);
  analogWrite(speedpin3,255);
  analogWrite(speedpin4,255);
  delay(2500);
  ping();
   duration=pulseIn(echopin,HIGH);
  while(duration>5500.00){
    ping();
    duration=pulseIn(echopin,HIGH);
    Serial.print("Right distance = ");
    Serial.println(duration);
    delay(100);
    forward();
  }
}
int turnleft()
{
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,HIGH);
  digitalWrite(dir5,LOW);
  digitalWrite(dir6,LOW);
  digitalWrite(dir7,LOW);
  digitalWrite(dir8,LOW);
  analogWrite(speedpin1,255);
  analogWrite(speedpin2,255);
  analogWrite(speedpin3,0);
  analogWrite(speedpin4,0);
  delay(2500);
  ping();
   duration=pulseIn(echopin,HIGH);
  while(duration>5500.00){
    ping();
    duration=pulseIn(echopin,HIGH);
    Serial.print("Left distance = ");
    Serial.println(duration);
    delay(100);
    forward();
  }
}
float rightD()
{
  float duration_r;
  myservo.write(15);
  delay(900);
  ping();
  duration_r=pulseIn(echopin,HIGH);
  myservo.write(90);
  Serial.print("Right Distance = ");
  Serial.println(duration_r);
  return duration_r;
}
float leftD()
{
  float duration_l;
  myservo.write(165);
  delay(900);
  ping();
  duration_l=pulseIn(echopin,HIGH);
  myservo.write(90);
  Serial.print("Left Distance = ");
  Serial.println(duration_l);
  return duration_l;
}
int ping()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin,LOW);
}

