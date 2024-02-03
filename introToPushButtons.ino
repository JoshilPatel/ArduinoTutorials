int buttonPin=6;
int LEDPin=9;
int buttonState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(LEDPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState=digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState==0){
    digitalWrite(LEDPin,HIGH);
  }
  delay(50);
  digitalWrite(LEDPin,LOW);


}
