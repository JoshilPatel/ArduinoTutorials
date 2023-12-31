void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT); // Working with pin 13 and it is an output 
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH); // Turn pin 13's LED on
delay(100);
digitalWrite(13,LOW); // Turn pin 13's LED off
delay(100);
}
