#include<SoftwareSerial.h>
SoftwareSerial BTSerial(2,3);
int m1a = 4;
int m1b = 5;
int m2a = 7;
int m2b = 8;
int en1 = 6;
int en2 = 9;
char Switchstate;
int trig = 12;
int echo = 13;
int distance = 0;
int duration = 0;
//BUZZER
int buzzer_plus=A1;
int buzzer_minus=A2;
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
pinMode(buzzer_plus,OUTPUT); 
pinMode(buzzer_minus,OUTPUT); 
}
void Stopp()
{
  analogWrite(6, 0);
  analogWrite(9, 0);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);

  }
void buzzer(){
  digitalWrite(buzzer_plus,HIGH); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,LOW); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,HIGH); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,LOW); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,HIGH); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,LOW); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,HIGH); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,LOW); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
  }
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration = pulseIn(echo,HIGH);
distance = duration*0.034/2;
Serial.print("distance: ");
Serial.println(distance); 
if(Serial.available()>0)

{
  
  Switchstate=Serial.read();
  BTSerial.write(Switchstate);
  
  
  }

if(BTSerial.available()>0)

{
  
  Switchstate=BTSerial.read();
  Serial.write(Switchstate);
  

 //BACKWARD
  if(Switchstate == 'B')
{
  analogWrite(6, 230);
  analogWrite(9, 230);
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
 
}
 //LEFT
 else if(Switchstate == 'R')
{
  analogWrite(6, 250);
  analogWrite(9, 240);
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);
  
}
  //RIGHT
  else if(Switchstate == 'L')
{
  analogWrite(6, 240);
  analogWrite(9, 250);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
  
}
  //STOP
  else if(Switchstate == 'S')
{
  analogWrite(6, 0);
  analogWrite(9, 0);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);
 
}
  

if(distance>=50)  
{ 
 
 if(Switchstate == 'F')//FORWARD
{
  digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration = pulseIn(echo,HIGH);
distance = duration*0.034/2;

  analogWrite(6, 240);
  analogWrite(9, 240);
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);
  delay(200);
}
}
}
//

if(distance>=40 && distance<=50)
//else
{

Stopp();
buzzer();   
delay(1500);
analogWrite(6, 230);
  analogWrite(9, 230);
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);
   delay(800);
  Stopp();
}
}
