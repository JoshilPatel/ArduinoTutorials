//For Temp Sensor
#include <DHT.h>
#define Type DHT11
int sensePin=2;
DHT HT(sensePin, Type); //DHT is an object from the DHT library
float humidity;
float tempC;
float tempF;

int setupTime=1000;

//For LCD
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Temp sensor
  HT.begin();
  delay(setupTime);

  //LCD
  lcd.begin(16,2); //6 columns and 2 rows  


}

void loop() {
  // put your main code here, to run repeatedly:
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true); //Need this for F for some reason

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("   Temperature C: ");
  Serial.print(tempC);
  Serial.print("C");
  Serial.print("   Temperature F: ");
  Serial.print(tempF);
  Serial.println("F");

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  delay(1000);

  lcd.clear();


}
