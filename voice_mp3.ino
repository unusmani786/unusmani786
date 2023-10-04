#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
 
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

String readSerial;

void setup() {
 
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  Serial.println(F("Voice Controlled mp3 player Demo."));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(20);  //Set volume value (0~30).

  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

}


void loop() { 
  if (Serial.available()) {
    readSerial = Serial.readStringUntil('#');
    Serial.println(readSerial);

  
    if (readSerial == "Azan") myDFPlayer.play(1); 
    
    
    else if (readSerial == "song 2") myDFPlayer.play(2); 
  
   
    else if (readSerial == "song 3") myDFPlayer.play(3);
    
    else if (readSerial == "song 4") myDFPlayer.play(4);  
    
    else if (readSerial == "stop music")    myDFPlayer.stop();

    else if (readSerial == "pause music")    myDFPlayer.pause();
    
    else if (readSerial == "resume music")    myDFPlayer.start();
    }
  
  
  
}
