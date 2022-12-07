

int moistureSensor = 0;
int motor = 2;

void setup() {
Serial.begin(9600);

pinMode(motor,OUTPUT);
  
  int SensorValue = analogRead(moistureSensor);
}
void loop()
{

  int SensorValue = analogRead(moistureSensor);
 

if(SensorValue >=400)
{
   
digitalWrite(motor,HIGH);

} 
else
{ 
digitalWrite(motor,LOW);

}
 }
