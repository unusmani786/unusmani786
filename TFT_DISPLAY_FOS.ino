#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>
#include <SoftwareSerial.h>

SoftwareSerial BluetoothSerial(10, 11); // RX, TX for Bluetooth module

char auth[] = "BaJMseLrTQENE0HEqjbKYHkfqwY-OoW9";
int rowIndex = 0;
String msg;
int totalBill = 0;
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin
#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define REDBAR_MINX 80
#define GREENBAR_MINX 130
#define BLUEBAR_MINX 180
#define BAR_MINY 30
#define BAR_HEIGHT 250
#define BAR_WIDTH 30

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define BLACK   0x0000
int BLUE = tft.color565(50, 50, 255);
#define DARKBLUE 0x0010
#define VIOLET 0x8888
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY   tft.color565(64, 64, 64);
#define GOLD 0xFEA0
#define BROWN 0xA145
#define SILVER 0xC618
#define LIME 0x07E0
int priceSprite = 40;
int pricePepsi = 40;
int priceCoke = 40;
int priceKabab = 20;
int priceDosa = 50;
int priceIdli = 60;
void drawHome()
{
  tft.fillScreen(WHITE);
  tft.drawRoundRect(0, 0, 319, 240, 8, WHITE);     //Page border
  tft.fillRoundRect(10, 30, 100, 40, 8, GOLD);
  tft.drawRoundRect(10, 30, 100, 40, 8, WHITE);  //Dish1
  tft.fillRoundRect(10, 80, 100, 40, 8, GOLD);
  tft.drawRoundRect(10, 80, 100, 40, 8, WHITE);  //Dish2
  tft.fillRoundRect(10, 130, 100, 40, 8, GOLD);   //Dish3
  tft.drawRoundRect(10, 130, 100, 40, 8, WHITE);
  tft.fillRoundRect(10, 180, 220, 40, 8, CYAN);
  tft.drawRoundRect(10, 180, 220, 40, 8, WHITE); //Call Waiter
  tft.fillRoundRect(130, 30, 100, 40, 8, GOLD);
  tft.drawRoundRect(130, 30, 100, 40, 8, WHITE);  //Dish4
  tft.fillRoundRect(130, 80, 100, 40, 8, GOLD);
  tft.drawRoundRect(130, 80, 100, 40, 8, WHITE); //Dish5
  tft.fillRoundRect(130, 130, 100, 40, 8, GOLD);
  tft.drawRoundRect(130, 130, 100, 40, 8, WHITE); //Dish6
  tft.fillRoundRect(10, 230, 220, 40, 8, MAGENTA);
  tft.drawRoundRect(10, 230, 220, 40, 8, WHITE); //Bill
  tft.fillRoundRect(10, 280, 220, 40, 8, GREEN);
  tft.drawRoundRect(10, 280, 220, 40, 8, WHITE); //Bill
  tft.setCursor(62, 0);
  tft.setTextSize(3);
  tft.setTextColor(LIME);
  tft.print(" Menu");
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(15, 37);
  tft.print(" SPRITE");
  tft.setCursor(15, 87);
  tft.print(" PEPSI");
  tft.setCursor(15, 137);
  tft.print("COKE");
  tft.setCursor(50, 187);
  tft.print(" Call Waiter");
  tft.setCursor(135, 37);
  tft.print(" KABAB");
  tft.setCursor(135, 87);
  tft.print(" DOSA");
  tft.setCursor(135, 137);
  tft.print(" IDLI");
  tft.setCursor(85, 237);
  tft.print(" BILL");
  tft.setCursor(95, 295);
  tft.print("WATER");
}

int oldcolor, currentcolor, currentpcolour;

void setup(void) {
  tft.reset();
  tft.begin(tft.readID());
  tft.setRotation(2);
  Serial.begin(9600);
  Serial.println();
  Serial.print("reading id...");
  delay(500);
  tft.fillScreen(BLACK);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(50, 140);
  tft.print("Loading...");
  for (int i; i < 250; i++) {
    tft.fillRect(BAR_MINY - 10, BLUEBAR_MINX, i, 10, RED);
    delay(0.000000000000000000000000000000000000000000000000001);
  }
  tft.fillScreen(BLACK);
  drawHome();
  pinMode(13, OUTPUT);
  BluetoothSerial.begin(9600); // Initialize Bluetooth serial communication
}

#define MINPRESSURE 10
#define MAXPRESSURE 1000

void transmit() {
  if (BluetoothSerial.available()) {
    BluetoothSerial.flush(); // Clear any previous data in the buffer
  }

  // Send the selected dish to the Bluetooth module
  BluetoothSerial.print(msg);
  BluetoothSerial.println(" Ordered");

 
if (msg == "Sprite") {
    totalBill += priceSprite;
    BluetoothSerial.print("Sprite 1ltr(Price: ");
    BluetoothSerial.print(priceSprite);
    BluetoothSerial.print(" Rs)");
  } else if (msg == "Pepsi") {
    totalBill += pricePepsi;
    BluetoothSerial.print("Pepsi 1ltr(Price: ");
    BluetoothSerial.print(pricePepsi);
    BluetoothSerial.print(" Rs)");
  } else if (msg == "Coke") {
    totalBill += priceCoke;
    BluetoothSerial.print("Coke 1ltr(Price: ");
    BluetoothSerial.print(priceCoke);
    BluetoothSerial.print(" Rs)");
  } else if (msg == "Kabab") {
    totalBill += priceKabab;
    BluetoothSerial.print("Kabab (Price: ");
    BluetoothSerial.print(priceKabab);
    BluetoothSerial.print(" Rs)");
  } else if (msg == "Dosa") {
    totalBill += priceDosa;
    BluetoothSerial.print("Dosa (Price: ");
    BluetoothSerial.print(priceDosa);
    BluetoothSerial.print(" Rs)");
  } else if (msg == "Idli") {
    totalBill += priceIdli;
    BluetoothSerial.print("Idli (Price: ");
    BluetoothSerial.print(priceIdli);
    BluetoothSerial.print(" Rs)");
  } else if (msg == "Bill") {
    BluetoothSerial.print("Total Bill: ");
    BluetoothSerial.print(totalBill);
    BluetoothSerial.print(" Rs");
  }
  
  BluetoothSerial.println();
}
// ... (previous code)

void loop() {
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > ts.pressureThreshhold) {
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);

    if (p.x > 30 && p.x < 70 && p.y > 130 && p.y < 230 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Sprite";
      transmit();
       delay(80);
      // ... (Rest of the code for handling Sprite)
    }
    
    // Handle Pepsi
    if (p.x > 80 && p.x < 120 && p.y > 130 && p.y < 230 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Pepsi";
      transmit();
      delay(80);
      // ... (Rest of the code for handling Pepsi)
    }
    
    // Handle Coke
    if (p.x > 130 && p.x < 170 && p.y > 130 && p.y < 230 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Coke";
      transmit();
       delay(80);
      // ... (Rest of the code for handling Coke)
    }
    
    // Handle Kabab
    if (p.x > 30 && p.x < 70 && p.y > 10 && p.y < 110 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Kabab";
      transmit();
      delay(80);
      // ... (Rest of the code for handling Kabab)
    }
    
    // Handle Dosa
    if (p.x > 80 && p.x < 120 && p.y > 10 && p.y < 110 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Dosa";
      transmit();
       delay(80);
      // ... (Rest of the code for handling Dosa)
    }
    
    // Handle Idli
    if (p.x > 130 && p.x < 170 && p.y > 10 && p.y < 110 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Idli";
      transmit();
      delay(80);
      // ... (Rest of the code for handling Idli)
    }
     
    
    // Handle Bill
    if (p.x > 230 && p.x < 270 && p.y > 10 && p.y < 230 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Bill";
       
      transmit();
       totalBill = 0; 
      delay(80);
      // ... (Rest of the code for handling Bill)
    }
    
    // Handle Water
    if (p.x > 280 && p.x < 320 && p.y > 10 && p.y < 230 && p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      msg = "Water";
      transmit();
      delay(80);
      // ... (Rest of the code for handling Water)
    }
  }
}
