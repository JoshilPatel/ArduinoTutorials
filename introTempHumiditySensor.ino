#include <DHT.h>
#define Type DHT11
int sensePin=2;
DHT HT(sensePin, Type); //DHT is an object from the DHT library
float humidity;
float tempC;
float tempF;

int setupTime=1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setupTime);

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

  delay(1000);


}
