int Xpin=A0;
int Ypin=A1;
int Spin=3;
int Xval;
int Yval;
int Sval;
int dt=200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Spin,INPUT);
  digitalWrite(Spin,HIGH); //Acts as a pull up resistor
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval=analogRead(Xpin);
  Yval=analogRead(Ypin);
  Sval=digitalRead(Spin);
  Serial.print("X val is: ");
  Serial.print(Xval);
  Serial.print("  Y val is: ");
  Serial.print(Yval);
  Serial.print("  Switch is: ");
  Serial.println(Sval);
  delay(dt);

}
