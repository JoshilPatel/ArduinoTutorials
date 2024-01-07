int readPin=A3;
int readVal=0; //Set to 0 just to set the variable up
float VOut=0; //Set to 0 just to set the vairable up
int delayTime=500;


void setup() {
  // put your setup code here, to run once:
  pinMode(readPin,INPUT);
  Serial.begin(9600); //Set up the serial monitor

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(readPin); //Reads a scaled number between 0 and 1023 (the voltage is scaled) | 1023 = 5V 0 = 0V
  VOut=(5./1023.)*readVal; //Need decimal points as it evaluates it as an integer otherwise
  Serial.println(VOut);
  delay(delayTime);


}
