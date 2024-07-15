//LCD
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//Ultrasonic sensor
int triggerPin=3;
int echoPin=2;
int pingTravelTime; //How long it takes for the ping to go from the sensor back to the receiver
float pingDistance;
float distanceToObject;


void setup() {
  // put your setup code here, to run once:

  //Ultrasonic sensor
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);  

//LCD
  lcd.begin(16,2); //6 columns and 2 rows

}

void loop() {
  // put your main code here, to run repeatedly:

  //Low, High, Low sequence sends out an ultrasonic pulse
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);

  pingTravelTime=pulseIn(echoPin,HIGH); //Looking through the echoPin and looking for a high pulse

  pingDistance = (0.03419856*pingTravelTime); //This is the total distance (there and back)
  distanceToObject = pingDistance/2;

//Displaying information
lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distanceToObject);
  lcd.print("cm");

  delay(1000);

  lcd.clear();
}
