int latchPin=11;
int clockPin=9;
int dataPin=12;

byte myByte=0b0000001;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin,LOW); //The latch pin needs to be set low to send data
  shiftOut(dataPin,clockPin,MSBFIRST,myByte); //Data pin is just to say that is where data is beign sent, sending data left to right so MSB first sending the data to the LEDs.
  digitalWrite(latchPin,HIGH); //Made high so expecting no more data 

  Serial.println(myByte,BIN);
  delay(1000);
  
  //myByte=myByte/2; //Logical shift right

  myByte=myByte*2; //Logical shift left
  
 
}
