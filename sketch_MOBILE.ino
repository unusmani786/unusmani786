#include<LiquidCrystal.h>

//count int rs 12, en = 11, d4 = 4, d5 = 3, d6 = 2, d7 = 5;
const int rs = 13, en = 12, d4 =7, d5 = 6, d6 = 5, d7 = 4;
int sw1=8;
int sw2=9;
int swread1;
int swread2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int count=0;

void setup()
{
  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
  start();
  lcd.begin(16,4);
  //lcd.setCursor(5, 3);
  lcd.print("DATE");
  lcd.setCursor(10, 0);
  lcd.print("SIM");
  lcd.setCursor(5, 2);
  lcd.print("BRAND");
  lcd.setCursor(0, 4);
  lcd.print("MENU");
  delay(100); 
  
}
void loop()
{
swread1=digitalRead(sw1);
swread2=digitalRead(sw2); 

if(swread1==LOW)
{
  count++;
  
  }
if(swread2==LOW)
{
  count--;
}  
 if(count==1)
 {
lcd.clear();
 lcd.setCursor(4, 1);
lcd.print("CONTACTS");
lcd.setCursor(0, 4);
  lcd.print("NEXT");
delay(200);
}
if(count==2)
{
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("GALLERY");
  lcd.setCursor(11, 4);
  lcd.print("BACK");
  lcd.setCursor(0, 4);
  lcd.print("NEXT");
  delay(200);
   }   

if(count==3)
{
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("MESSEGES");
  lcd.setCursor(11, 4);
  lcd.print("BACK");
  lcd.setCursor(0, 4); 
   lcd.print("NEXT");
   delay(200);
   }   
if(count==4)
{
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("GAMES");
   lcd.setCursor(11, 4);
  lcd.print("BACK");
  lcd.setCursor(0, 4); 
   lcd.print("NEXT");
   delay(200);
   }   
if(count==5)
{
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("MUSIC");
  lcd.setCursor(11, 4);
  lcd.print("BACK");
  lcd.setCursor(0, 4); 
   lcd.print("NEXT");
  delay(200);
  
   }   

if(count==6)
{
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("CALCULATOR");
  lcd.setCursor(11, 4);
  lcd.print("BACK");
  lcd.setCursor(0, 4); 
   lcd.print("NEXT");
  delay(200);
  
  }
if(count==7)
{
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("SETTINGS");
  lcd.setCursor(12, 4);
  lcd.print("BACK");
  lcd.setCursor(0, 4); 
   lcd.print("MAIN SCR");
  delay(200);
  
}  
 if(count==8)
 {
 count=0;
 }
if(count==0)
{
delay(200);
start();  
}
}
void start()
{
 lcd.clear();
 lcd.print("18-9-22");
  lcd.setCursor(10, 0);
  lcd.print("AIRTEL");
  lcd.setCursor(5, 2);
  lcd.print("NOKIA");
  lcd.setCursor(0, 4);
  lcd.print("MENU");
  delay(100);  
 }



  
  
