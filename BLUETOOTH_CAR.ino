#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2,3);
int m1a = 4;
int m1b = 5;
int m2a = 6;
int m2b = 7;
int en1 = 9;
int en2 = 10;
char Switchstate;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BTSerial.begin(9600);
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
pinMode(en1, OUTPUT);
pinMode(en2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)

{
  
  Switchstate=Serial.read();
  BTSerial.write(Switchstate);
  
  
  }

if(BTSerial.available()>0)

{
  
  Switchstate=BTSerial.read();
  Serial.write(Switchstate);
  
  
  
//FORWARD
if (Switchstate == 'F')
{
  analogWrite(9, 200);
  analogWrite(10, 200);
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
  delay(200);
}
 //BACKWARD
 if(Switchstate == 'B')
{
  analogWrite(9, 190);
  analogWrite(10, 190);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);
 
}
 //LEFT
 if(Switchstate == 'L')
{
  analogWrite(9, 200);
  analogWrite(10, 0);
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);
  
}
  //RIGHT
  if(Switchstate == 'R')
{
  analogWrite(9, 0);
  analogWrite(10, 200);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
  
}
  //STOP
  if(Switchstate == 0)
{
  analogWrite(6, 0);
  analogWrite(11, 0);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);
 
}
  }
}
