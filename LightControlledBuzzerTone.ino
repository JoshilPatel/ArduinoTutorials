int lightPin=A0;
int lightVal;
int buzzPin=7;
int buzzTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin,INPUT);
  pinMode(buzzPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightPin);
  buzzTime=3.8*lightVal+90;
  


  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(buzzTime);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(buzzTime);


}
