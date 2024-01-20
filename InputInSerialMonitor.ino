int numBlinks;
int redLED=7;
int j;
String msg="How many times do you want to blink the LED?";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while (Serial.available()==0){ //Wait for someone to enter a value before moving on
}

numBlinks=Serial.parseInt();
for (j=1;j<=numBlinks;j=j+1){
  digitalWrite(redLED,HIGH);
  delay(500);
  digitalWrite(redLED,LOW);
  delay(500);
}

}
