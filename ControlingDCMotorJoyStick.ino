int speedPin=5;
int directionPin1=4; //High clockwise
int directionPin2=3; //Low clockwise
float mSpeed;
int jPin=A1;
int jVal;


void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin,OUTPUT);
  pinMode(directionPin1,OUTPUT);
  pinMode(directionPin2,OUTPUT);
  pinMode(jPin,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  jVal=analogRead(jPin);
  Serial.println(jVal);
  delay(200);

if (jVal==505 || jVal==504){
  analogWrite(speedPin,0); 
}

if (jVal>505){
  mSpeed=jVal*(255./518.)-249;
  analogWrite(speedPin,mSpeed);
  digitalWrite(directionPin1,HIGH);
  digitalWrite(directionPin2,LOW);
}

if (jVal<504){
  mSpeed=jVal*(255./-505.)+255;
  analogWrite(speedPin,mSpeed);
  digitalWrite(directionPin1,LOW);
  digitalWrite(directionPin2,HIGH);
}

}
