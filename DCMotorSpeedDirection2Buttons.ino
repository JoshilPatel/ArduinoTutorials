int speedPin=5; // Controls speed by giving an analogue write
int dirPin1=4; //Direction pin (one high, one low for direction)
int dirPin2=3; //Directon pin
int mSpeed=0; //Will be written to speed pin

int buttonPin1=8;
int buttonPin2=9;
int buttonVal1;
int buttonVal2;


void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);

  pinMode(buttonPin1,INPUT);
  digitalWrite(buttonPin1,HIGH);

  pinMode(buttonPin2,INPUT);
  digitalWrite(buttonPin2,HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonVal1=digitalRead(buttonPin1);
  buttonVal2=digitalRead(buttonPin2);
  Serial.print("Motor Speed: ");
  Serial.println(mSpeed);

if (buttonVal1==0){
  mSpeed=mSpeed-10;
  delay(500);  
}

if (buttonVal2==0){
  mSpeed=mSpeed+10;
  delay(500);
}

//Clips speed at max clockwise
if (mSpeed>255){
  mSpeed=255;
}

//Clips speed at max anticlockwise
if (mSpeed<-255){
  mSpeed=-255;
}

//Going up from 0 to increase clockwise speed
if (mSpeed==10){
  mSpeed=80;
}

//Going up from 0 to increase ant-clockwise speed
if (mSpeed==-10){
  mSpeed=-80;
}

//When coming down from 255 or 250
if (mSpeed==70 || mSpeed ==75){
  mSpeed=0;
}

//When coming up from -255 or 250
if (mSpeed==-70 || mSpeed==-75){
  mSpeed=0;
}

if (mSpeed==0){
  analogWrite(speedPin,0);
}

if (mSpeed>0){
  digitalWrite(dirPin1,LOW); //Direction
  digitalWrite(dirPin2,HIGH); //Direction  
  analogWrite(speedPin,mSpeed);
}

if (mSpeed<0){
  digitalWrite(dirPin1,HIGH); //Direction
  digitalWrite(dirPin2,LOW); //Direction  
  analogWrite(speedPin,abs(mSpeed));
}

}

