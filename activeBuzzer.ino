int myNum;
int buzzPin=8;
int potPin=A0;
int potVal;
String msg="Please input your number";
int dt=2000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzPin,OUTPUT);
pinMode(potPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:]
potVal=analogRead(potPin);
Serial.println(potVal);
while(potVal>1000){
  digitalWrite(buzzPin,HIGH);
  potVal=analogRead(potPin);
  Serial.println(potVal);
}
digitalWrite(buzzPin,LOW);
}
