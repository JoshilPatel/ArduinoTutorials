int yellowLED=9;
int redLED=8;
int yellowTime=500;
int redTime=500;
int yellowBlinks=5;
int redBlinks=3;
int j;


void setup() {
  // put your setup code here, to run once:
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(j=1;j<=yellowBlinks;j=j+1){
  digitalWrite(yellowLED,HIGH);
  delay(yellowTime);
  digitalWrite(yellowLED,LOW);
  delay(yellowTime);
  }

  for(j=1;j<=redBlinks;j=j+1){
  digitalWrite(redLED,HIGH);
  delay(redTime);
  digitalWrite(redLED,LOW);
  delay(redTime);
  }

}
