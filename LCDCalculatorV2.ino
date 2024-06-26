#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

float num1;
float num2;
float answer;

String operation;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); //6 columns and 2 rows
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Input 1st number");
  while (Serial.available()==0){} //Waiting for a response
  num1=Serial.parseFloat();

  lcd.clear();


  lcd.print("Input 2nd number");
  while (Serial.available()==0){} //Waiting for a response
  num2=Serial.parseFloat();

  lcd.clear();

  lcd.print("Input (+,-,*,/)");
  while (Serial.available()==0){} //Waiting for a response
  operation=Serial.readString();

  if (operation=="+"){
    answer=num1+num2;
  }

  if (operation=="-"){
    answer=num1-num2;
  }  

  if (operation=="*"){
    answer=num1*num2;
  }  

  if (operation=="/"){
    answer=num1/num2;
  }  

lcd.clear();

lcd.print(num1);
lcd.print(operation);
lcd.print(num2);
lcd.print(" = ");
lcd.print(answer);
delay(5000);
lcd.clear();
}
