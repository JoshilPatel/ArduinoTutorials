byte myByte=0X0; //Put 0x before a number to make it a hexadecimal number, use B before number for it to be binary
int dt=500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(myByte,HEX); //Can print out in binary using BIN and HEX OR DEC
  Serial.print(" ");
  Serial.print(myByte,BIN);
  Serial.print(" ");
  Serial.println(myByte,DEC);  

  myByte = myByte+1;
  delay(dt);

}
