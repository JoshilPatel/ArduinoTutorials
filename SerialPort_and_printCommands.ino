int j=1;
int waitT=750;
int x=12;
int y=11;
int z;
float pi=3.14;
float r=2;
float area;

String myString=" + "; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
area=pi*r*r;
Serial.print("A circle with radius ");
Serial.print(r);
Serial.print(" has an area of ");
Serial.println(area);
r=r+0.5;

}
