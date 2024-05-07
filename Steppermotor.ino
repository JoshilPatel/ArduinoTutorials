#include <Stepper.h>
int stepsPerRevolution = 2048; //This needs to be gotten off the spec sheet.
int motorSpeed = 5; // 10 rpm
int dt=500;

int buttonPin=2;
int motorDirection=1; //1 = forwards and -1 = backwards
int buttonValNew; //This will track the new value of the button
int buttonValOld=1; //This will track the old value of the button, =1 because it starts off as not pressed



Stepper myStepper(stepsPerRevolution, 8,10,9,11); //This is the pin sequence for that particular stepper motor and that driver.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motorSpeed); //Setting the speed the stepper motor turns at 
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH); //Causes the button value to be read as a 1, removes need of pull up resistor
}

void loop() {
  buttonValNew=digitalRead(buttonPin);
  if (buttonValOld==1 && buttonValNew==0){ //This represents a transition taking place, goes from not being pressed to having been pressed.
    motorDirection = motorDirection*(-1); //Changes the direction
    buttonValNew = buttonValOld;
  }
  
  myStepper.step(motorDirection*1); //Going one step in either positive or negative direction

}
 