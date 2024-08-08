#include <IRremote.h>
int IRpin=9;

//Create IR object
IRrecv IR(IRpin);
//When it reads from the module this is where it stores it
decode_results cmd;
String myCommand;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();


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
  }

  if (cmd.value==0xFF4AB5){
    myCommand="zero";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF52AD){
    myCommand="hash";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF10EF){
    myCommand="seven";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF38C7){
    myCommand="eight";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF5AA5){
    myCommand="nine";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF30CF){
    myCommand="four";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF18E7){
    myCommand="five";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF7A85){
    myCommand="six";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF6897){
    myCommand="one";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF9867){
    myCommand="two";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF9867){
    myCommand="two";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFFB04F){
    myCommand="three";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFFA857){
    myCommand="down";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF02FD){
    myCommand="ok";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF22DD){
    myCommand="left";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFFC23D){
    myCommand="right";
    Serial.println(myCommand);
  }

  if (cmd.value==0xFF629D){
    myCommand="up";
    Serial.println(myCommand);
  }


}