#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <SPI.h>
#include <MFRC522.h>
// Define pins
#define TRIGGER_PIN 22 // Trigger pin for ultrasonic sensor
#define ECHO_PIN 23   // Echo pin for ultrasonic sensor

// SoftwareSerial for Bluetooth, DFPlayer Mini, and Debugging
SoftwareSerial bluetoothSerial(12, 13); // RX, TX for Bluetooth module

// Serial1 for DFPlayer Mini (TX1 and RX1 on Arduino Mega)
SoftwareSerial dfPlayerSerial(10, 11); // RX1, TX1 for DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;
#define SS_PIN 53
#define RST_PIN 5
String data;
//char dl;
String uid;
int tableNumber;
int buzzer_plus=A0;
int buzzer_minus=A3 ;
MFRC522 rfid(SS_PIN, RST_PIN);
// Motor control pins
#define m1a 3
#define m1b 4  
#define m2a 6
#define m2b 7
#define ENA 8 // Change ENA to 6
#define ENB 9

char command = 'S'; // Initialize with 'S' for stop
int targetTable = 1; // Specify the table number you want to read
void buzzer(){
digitalWrite(buzzer_plus,HIGH); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,LOW); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
digitalWrite(buzzer_plus,LOW); 
digitalWrite(buzzer_minus,LOW); 
delay(500);
}
void setup() {
  Serial.begin(9600); // Initialize Serial for debugging
   SPI.begin();
  rfid.PCD_Init();
  // Initialize DFPlayer Mini communication
  dfPlayerSerial.begin(9600);
  if (!myDFPlayer.begin(dfPlayerSerial)) {
    Serial.println("Unable to begin DFPlayer Mini:");
    Serial.println("1. Please recheck the connection!");
    Serial.println("2. Please insert the SD card!");
    while (true);
  }
  myDFPlayer.volume(30); // Set the volume (0-30)

  // Initialize Bluetooth communication
  bluetoothSerial.begin(9600);
  pinMode(buzzer_plus,OUTPUT); 
pinMode(buzzer_minus,OUTPUT); 
  // Motor control pins setup
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(ENA, OUTPUT); // Change ENA to 6
  pinMode(ENB, OUTPUT);

  // Ultrasonic sensor pins setup
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void forward() {
  analogWrite(ENA, 240);
  analogWrite(ENB, 180);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  delay(200);
}

void stopp() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  delay(200);
}
void ultra()
  {
  // Ultrasonic sensor code to detect obstacles
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  unsigned int distance = duration * 0.034 / 2;
   Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm"); 
  // Check for obstacles and play audio if needed
  if (distance <= 20) {
    stopp();
    myDFPlayer.play(1); // Play audio when an obstacle is detected
    delay(5000); // Play for 5 seconds
    myDFPlayer.stop(); // Stop playing
    delay(1000); // Delay before playing another track
    myDFPlayer.play(2);
     delay(1000);
     forward();
  }
} 
void loop() {
 
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uid = getUID();

    if (tableMatches(uid)) {
      serveTable(targetTable);
    }

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
    Serial.print("Received Bluetooth Command: ");
    Serial.println(command);
  }

  // Perform actions based on the received command
  switch (command) {
    case '1': // Move forward
     
      targetTable = 1;
      forward();
      break;
    case '2': // Move forward
       targetTable = 2;
      forward();
     
      break;
    case '3': // Move forward
     targetTable = 3;
      forward();
     
      break;
    case 'S': // Stop
      stopp();
      break;
    default:
      // Invalid command or do nothing
      break;
  }
 ultra();
}
String getUID() {
  String uid = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    uid += String(rfid.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  return uid;
}

bool tableMatches(String uid) {
  if (targetTable == 1 && uid == "D3162142") {
   
    stopp();
    
    buzzer(); 
    return true;
    
  } else if (targetTable == 3 && uid == "53C36043") {
     
    stopp();
    buzzer(); 
    return true;
    
  } else if (targetTable == 2 && uid == "E3D09FA9") {

    stopp();
    buzzer(); 
    
    return true;
    
  }

  return false;
}


void serveTable(int tableNumber) {
  Serial.print("Serving table ");
  Serial.println(tableNumber);

  // Code to serve the table goes here
}
