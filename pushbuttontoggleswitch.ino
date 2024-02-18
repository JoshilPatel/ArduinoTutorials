int LEDState=0;
int redLED=8;
int buttonPin=11;
int buttonNew;
int buttonOld=1;
int dt=50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED,OUTPUT);
  pinMode(buttonPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonNew=digitalRead(buttonPin);
  if (buttonOld==0 && buttonNew==1){
    if (LEDState==0){
      digitalWrite(redLED,HIGH);
      LEDState=1;
    }
    else{digitalWrite(redLED,LOW);
    LEDState=0;
    }
  }
  buttonOld=buttonNew;
  delay(dt);

}
