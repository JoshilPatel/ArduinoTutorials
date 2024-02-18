#include <Servo.h>
int servoPin=9;
float servoPos;
Servo myServo;

int lightPin=A0;
int lightVal;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(lightPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  servoPos = (-0.28*lightVal) + 165;
  myServo.write(servoPos);

}
