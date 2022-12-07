#include <LiquidCrystal.h>

int sw1 = 9;
int sw2 = 10;
int swread1;
int swread2;
int count=0; 
int const rs = 6, en = 7, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
 lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("ANDROID");
  lcd.setCursor(0, 2);
  lcd.print("NEXT");
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  
 }

void loop()
{
swread1=digitalRead(sw1); 
swread2=digitalRead(sw2);
//start();



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
//lcd.clear();
 lcd.setCursor(4, 0);
lcd.print("CONTACTS");
lcd.setCursor(11, 2);
  lcd.print("NEXT");
delay(200);
}
if(count==2)
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("GALLERY");
  lcd.setCursor(0, 2);
  lcd.print("BACK");
  lcd.setCursor(11, 2);
  lcd.print("NEXT");
  delay(200);
   }   

if(count==3)
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("MESSEGES");
  lcd.setCursor(0, 2);
  lcd.print("BACK");
  lcd.setCursor(11, 2); 
   lcd.print("NEXT");
   delay(200);
   }   
if(count==4)
{
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("GAMES");
   lcd.setCursor(0, 2);
  lcd.print("BACK");
  lcd.setCursor(11, 2); 
   lcd.print("NEXT");
   delay(200);
  count = 0;
   }   
/*if(count==5)
{
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("MUSIC");
  lcd.setCursor(0, 2);
  lcd.print("BACK");
  lcd.setCursor(11, 2); 
   lcd.print("NEXT");
  delay(200);
  
   }   

if(count==6)
{
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("CALCULATOR");
  lcd.setCursor(0, 2);
  lcd.print("BACK");
  lcd.setCursor(11, 2); 
   lcd.print("NEXT");
  delay(200);
  
  }
if(count==7)
{
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("SETTINGS");
  lcd.setCursor(0, 2);
  lcd.print("BACK");
  lcd.setCursor(11, 2); 
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
 lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("ANDROID");
  /*lcd.setCursor(0, 2);
  lcd.print("BACK");*/
 // lcd.setCursor(11, 2);
 // lcd.print("NEXT")
 }
