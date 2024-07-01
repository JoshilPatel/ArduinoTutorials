int triggerPin=12;
int echoPin=11;
int pingTravelTime; //How long it takes for the ping to go from the sensor back to the receiver
float pingDistance;
float distanceToObject;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Low, High, Low sequence sends out a pulse
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);

  pingTravelTime=pulseIn(echoPin,HIGH); //Looking through the echoPin and looking for a high pulse

  pingDistance = (0.03419856*pingTravelTime); //This is the total distance (there and back)
  distanceToObject = pingDistance/2;

  Serial.print("Distance to object: ");
  Serial.print(distanceToObject);
  Serial.println("3cm");
  delay(1000);

}
