    #include<Servo.h>
        int flag=1;
      const int trig = 8;
      const int echo = 9;
      int i;
      int m1a = 2;
      int m1b = 3;
      int m2a = 4;
      int m2b = 5;
      int en1 = 6;
      int en2 = 11;
      int duration = 0;
      int dis1=0;
      int dis2=0;
      int distance = 0;
      int led1=7; 
      int led2=12;
      //int s = 13;
      //int sread;
      Servo Myservo;
      int pos;
      void setup() 
      {
        pinMode(trig , OUTPUT);
        pinMode(echo , INPUT);
        pinMode(2 , OUTPUT);
        pinMode(3 , OUTPUT);
        pinMode(4 , OUTPUT);
        pinMode(5 , OUTPUT);
        pinMode(led1 , OUTPUT);
        pinMode(led2 , OUTPUT);
       //pinMode(s, INPUT);
        Myservo.attach(10);
      
        Serial.begin(9600);
       
      }
      void ledblink(){
        for(i=0;i<=3;i++)
        {
          digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH);
          delay(70);
       digitalWrite(led1,LOW);
       digitalWrite(led2,LOW);
           delay(70);
        }
      }
      
      void ledblink1(){
        for(i=0;i<=2;i++)
        {
          digitalWrite(led1,HIGH);
          delay(70);
       digitalWrite(led1,LOW);
           delay(70);
        }
      }
      void ledblink2(){
        
          for(i=0;i<=2;i++)
        {
          digitalWrite(led2,HIGH);
          delay(50);
       digitalWrite(led2,LOW);
           delay(50);
        }
      }
      void loop()
      {
      //sread = digitalRead(s);
      
      
        if(flag==1)
        {
         ledblink();
           delay(1500);
          flag=0;
      
          }
      
         ledblink2();
         Myservo.write(90);
         delay(20);
        
        digitalWrite(trig , HIGH);
        delayMicroseconds(10);
        digitalWrite(trig , LOW);
      
        duration = pulseIn(echo, HIGH);
      distance = duration * 0.034/2;
      
        Serial.println(distance);
        //Serial.println(ldis);
        //Serial.println(rdis);
        
        if(distance<=70)
      {
        analogWrite(6, 100);
        analogWrite(11, 100);
        digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, HIGH);
         digitalWrite(m2b, LOW);
        }
       
       if(distance<=65)
      {
        analogWrite(6, 90);
        analogWrite(11, 90);
        digitalWrite(m1a, HIGH);
        digitalWrite(m1b, LOW);
         digitalWrite(m2a, HIGH);
         digitalWrite(m2b, LOW);
        }
       
       if(distance<58)
       {
        //backward
        analogWrite(6, 140);
        analogWrite(11, 140);
        digitalWrite(m1a, LOW);
        digitalWrite(m1b, HIGH);
        digitalWrite(m2a, LOW);
        digitalWrite(m2b, HIGH);
          ledblink1();
          
        
         //STOP
         ledblink1();
        analogWrite(6, 0);
        analogWrite(11, 0);
        digitalWrite(m1a, LOW);
        digitalWrite(m1b, LOW);
        digitalWrite(m2a, LOW);
        digitalWrite(m2b, LOW);
          ledblink1();
          delay(1500);
           ledblink1();
         //SERVO
         //LOOK LEFT
         Myservo.write(180);
      
          digitalWrite(trig , HIGH);
        delayMicroseconds(10);
        digitalWrite(trig , LOW);
      
        duration = pulseIn(echo, HIGH);
      dis1 = duration * 0.034/2;
      Serial.print("dis1:=");
         Serial.println(dis1);
         ledblink1();
         delay(500);
         
         Myservo.write(0);
         digitalWrite(trig , HIGH);
        delayMicroseconds(10);
        digitalWrite(trig , LOW);
      
        duration = pulseIn(echo, HIGH);
      dis2 = duration * 0.034/2;
      Serial.print("dis2:=");
      Serial.println(dis2);
      ledblink1();    
          delay(500);
       Myservo.write(90);
       
        if(dis2>=dis1){
           
         analogWrite(6, 200);
         analogWrite(11, 0);
         digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, LOW);
         digitalWrite(m2b, LOW); 
         delay(800);
       
         // forward
         analogWrite(6, 250);
        analogWrite(11, 240);
        digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, HIGH);
         digitalWrite(m2b, LOW);
        }
           else 
          {
          analogWrite(6, 0);
         analogWrite(11, 200);
         digitalWrite(m1a, LOW);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, HIGH);
         digitalWrite(m2b, LOW); 
         delay(800);
       
         // forward
         analogWrite(6, 250);
        analogWrite(11, 240);
        digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, HIGH);
         digitalWrite(m2b, LOW);
            
            }
        
       }
       if (distance>70)
      {
       
        
        Myservo.write(90);
        delay(5);
        
        analogWrite(6, 250);
        analogWrite(11, 240);
        digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         digitalWrite(m2a, HIGH);
         digitalWrite(m2b, LOW);
        
      }
      
      
      }
