 int redLED=10;
 int leftButton=5;
 int leftButtonState;
 int rightButton=6;
 int rightButtonState;
 int brightness=0;
 
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED,HIGH);
  pinMode(leftButton,INPUT);
  pinMode(rightButton,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  leftButtonState=digitalRead(leftButton);
  rightButtonState=digitalRead(rightButton);

 if (leftButtonState==0){
  brightness=brightness-15;
 }

 if (rightButtonState==0){
  brightness=brightness+15;
 }

 if (brightness<=0){
  brightness=0;
 }

 if (brightness>=255){
  brightness=255;
 }

Serial.println(brightness);
analogWrite(redLED,brightness);
delay(250);
}
