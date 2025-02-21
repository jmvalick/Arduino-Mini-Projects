#include <Stepper.h>
int stepsPerRev = 2048;
Stepper myStepper(stepsPerRev,8,10,9,11);
int motSpeed = 5;
int button = 2;
int newRead;
int oldRead;
int motDir = 1;

void setup() {

  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);

}

void loop() {

  newRead = digitalRead(button);

  if (oldRead == 1 and newRead == 0){
    motDir = motDir*-1;
  }
  
  myStepper.step(motDir*1);

  oldRead = newRead;
}
