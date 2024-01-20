int redLED=3;
int blueLED=2;
int greenLED=4;
String question="Which colour LED do you want to light?";
String choice;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redLED,OUTPUT);
pinMode(blueLED,OUTPUT);
pinMode(greenLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(question);
while (Serial.available()==0){

}

choice=Serial.readString();

if (choice=="red"){
  digitalWrite(redLED,HIGH);
  digitalWrite(greenLED,LOW);
  digitalWrite(blueLED,LOW);
}

if (choice=="blue"){
  digitalWrite(redLED,LOW);
  digitalWrite(greenLED,LOW);
  digitalWrite(blueLED,HIGH);
}

if (choice=="green"){
  digitalWrite(redLED,LOW);
  digitalWrite(greenLED,HIGH);
  digitalWrite(blueLED,LOW);
}

delay(500);

}
