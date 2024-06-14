int latchPin=11;
int clockPin=9;
int dataPin=12;
byte LED1=0b10101010; //Lightng the LEDs, could put in as hex, binary or decimal (0x for hex and ob for binary)
byte LED2=0b01010101;


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
  shiftOut(dataPin,clockPin,MSBFIRST,LED1); //Data pin is just to say that is where data is beign sent, sending data left to right so MSB first sending the data to the LEDs.
  digitalWrite(latchPin,HIGH); //Made high so expecting no more data

  delay(100);

  digitalWrite(latchPin,LOW); //The latch pin needs to be set low to send data
  shiftOut(dataPin,clockPin,MSBFIRST,LED2); //Data pin is just to say that is where data is beign sent, sending data left to right so MSB first sending the data to the LEDs.
  digitalWrite(latchPin,HIGH); //Made high so expecting no more data

  delay(100);



}
