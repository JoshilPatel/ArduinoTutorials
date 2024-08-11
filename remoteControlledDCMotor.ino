#include <IRremote.h>
int IRpin=9;

//Create IR object
IRrecv IR(IRpin);
//When it reads from the module this is where it stores it
decode_results cmd;
String myCommand;

//MOTOR SET UP
int speedPin=5; // Controls speed by giving an analogue write
int dirPin1=4; //Direction pin (one high, one low for direction)
int dirPin2=3; //Directon pin
int mSpeed=0; //Will be written to speed pin

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();

  //MOTOR
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);

}

void loop() {

  //&cmd is getting a value back from the function
  while (IR.decode(&cmd)==0){} //Do nothing untilo someone presses a button
  
  Serial.println(cmd.value,HEX);
  //Go back and start reading again
  delay(1500);
  IR.resume();

  if (cmd.value==0xFF42BD){
    myCommand="star";
    Serial.println(myCommand);
    mSpeed=0;
    analogWrite(speedPin,mSpeed);
  }

  if (cmd.value==0xFF52AD){
    myCommand="hash";
    Serial.println(myCommand);
    digitalWrite(dirPin1,LOW);
    digitalWrite(dirPin2,HIGH);
    mSpeed=255;
    analogWrite(speedPin,mSpeed);
  }


  if (cmd.value==0xFF629D){
    myCommand="up";
    Serial.println(myCommand);
    mSpeed=mSpeed+15;
    if (mSpeed<65){
      mSpeed=65;
    }
    if (mSpeed>255){
      mSpeed=255;
    }
    analogWrite(speedPin,mSpeed);
    Serial.println(mSpeed);
  }

  if (cmd.value==0xFFA857){
    myCommand="down";
    Serial.println(myCommand);
    mSpeed=mSpeed-15;
    if (mSpeed<65){
      mSpeed=0;
    }
    analogWrite(speedPin,mSpeed);
    Serial.println(mSpeed);
  }


  if (cmd.value==0xFF22DD){
    myCommand="left";
    Serial.println(myCommand);
    digitalWrite(dirPin1,HIGH);
    digitalWrite(dirPin2,LOW);
    analogWrite(speedPin,mSpeed);
  }

  if (cmd.value==0xFFC23D){
    myCommand="right";
    Serial.println(myCommand);
    digitalWrite(dirPin1,LOW);
    digitalWrite(dirPin2,HIGH);
    analogWrite(speedPin,mSpeed);
  }

}