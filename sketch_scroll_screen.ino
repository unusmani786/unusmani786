#include<LiquidCrystal.h>
const int rs=8, en=9, d4=5, d5=4, d6=3, d7=2;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void loop() {
  count_countdown();
  delay(600);
  scroll_left();
  delay(600);
  scroll_right();
}

//Displays the numbers from 0 to 9
void count_countdown(){
 lcd.setCursor(0,0);      
   for (int thisChar = 0; thisChar < 10; thisChar++) {
      lcd.print(thisChar);
      delay(500);
  }
  //Changes line and displays the numbers from 9 to 0
  lcd.setCursor(0,1);
    for (int thisChar =9; thisChar>=0; thisChar--) {
      lcd.print(thisChar);
       delay(500);
  }
  }

//Scrolls message from left to right
void scroll_left(){
  lcd.begin(16, 2);
  lcd.print("Scrolling message!");
  delay(1000);
    for (int positionCounter = 0; positionCounter < 18; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  delay(600);
}

//Scrolls message from right to left
void scroll_right(){
  lcd.begin(16, 2);
  lcd.print("Scrolling message!");
  delay(1000);
    for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);

    }
}
/*void setup() {
lcd.begin(16, 2);
//lcd.setCursor()
lcd.print("hello students");
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

 }*/
    
