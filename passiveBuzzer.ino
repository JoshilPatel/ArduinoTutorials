int buzzPin=8;
int potPin=A0;
int potVal;
int buzzTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  pinMode(potPin,INPUT);

}

void loop() {
   //put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  //Serial.print("potVal= "); FOR SOME REASON THE PRINT STATEMENTS STOP THE BUZZER FROM WORKING CORRECTLY.
  //Serial.println(potVal);

  buzzTime = (potVal*9.73)+50;
  //Serial.print("buzzTime= ");
  //Serial.println(buzzTime);


  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(buzzTime);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(buzzTime);

}
