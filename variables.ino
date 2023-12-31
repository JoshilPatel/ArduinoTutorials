//Set variables
int redLED=8;
float pi=3.14;
int dit=200;
int dah=500;

void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(redLED,HIGH);
delay(dit);
digitalWrite(redLED,LOW);
delay(dah);
}
