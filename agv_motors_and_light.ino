#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);
int m1a = 2;
int m1b = 3;
int m2a = 4;
int m2b = 5;
//
int blue=6;
int red=7;
int yellowleft=8;
int yellowright=9; 
char Switchstate;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BTSerial.begin(9600);
pinMode(m1a, OUTPUT);
pinMode(m1b, OUTPUT);
pinMode(m2a, OUTPUT);
pinMode(m2b, OUTPUT);
//
pinMode(blue,OUTPUT);   //left motors forward
pinMode(red,OUTPUT);   //left motors reverse
pinMode(yellowleft,OUTPUT);   //right motors forward
pinMode(yellowright,OUTPUT);   //right motors reverse
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
  digitalWrite(blue,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(yellowleft,HIGH);
  digitalWrite(yellowright,HIGH);

  //
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  //digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);

}
 //BACKWARD
 if(Switchstate == 'B')
{
  digitalWrite(blue,HIGH);
  digitalWrite(red,LOW);
  delay(200);
  digitalWrite(red,HIGH);
   delay(200);
  digitalWrite(red,LOW);
   delay(200);
  digitalWrite(red,HIGH);
   delay(200);
  digitalWrite(yellowleft,HIGH);
  digitalWrite(yellowright,HIGH);
  //
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
 
}
 //LEFT
 if(Switchstate == 'L')
{
   digitalWrite(blue,HIGH);
    digitalWrite(red,HIGH);
  digitalWrite(yellowleft,HIGH);
  digitalWrite(yellowright,LOW);

  //
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);
  
}
  //RIGHT
  if(Switchstate == 'R')
{
 digitalWrite(blue,HIGH);
  digitalWrite(red,HIGH);
  digitalWrite(yellowleft,LOW);
  digitalWrite(yellowright,HIGH);

  //
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
  
}
 if(Switchstate == 'S'){      //STOP (all motors stop)
   digitalWrite(blue,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(yellowleft,HIGH);
  digitalWrite(yellowright,HIGH);

  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,HIGH);

} 
  
  }
}
