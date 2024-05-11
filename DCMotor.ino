int speedPin=5; // Controls speed by giving an analogue write
int dirPin1=4; //Direction pin (one high, one low for direction)
int dirPin2=3; //Directon pin
int motorSpeed=90; //Will be written to speed pin


void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin1,LOW); //Direction
  digitalWrite(dirPin2,HIGH); //Direction

  analogWrite(speedPin,255); //This is just to kick start the motor
  delay(100);
  analogWrite(speedPin,motorSpeed); //Turning the motor on
  delay(5000);

}
