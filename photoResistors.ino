int lightPin=A0;
int lightVal;
int dt=250;
int greenLED=7;
int redLED=8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin,INPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);


}

void loop() {
   //put your main code here, to run repeatedly:
   lightVal=analogRead(lightPin);
   Serial.println(lightVal);
   
  
  if (lightVal<=800){
    digitalWrite(redLED,HIGH);
    digitalWrite(greenLED,LOW);
  }

  if (lightVal>800){
    digitalWrite(greenLED,HIGH);
    digitalWrite(redLED,LOW);
  }


}
