//Set variables
int redLED=4;
float pi=3.14;
int dit=200;
int dah=500;
String myName="Joshil";

void setup() {
  // put your setup code here, to run once:
pinMode(redLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(redLED,HIGH);
delay(dit);
digitalWrite(redLED,LOW);
delay(dah);
}
