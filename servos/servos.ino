#include <Servo.h>

int servo = 9;
int position = 50;
Servo myServo;

void setup() {
 
  Serial.begin(9600);
  myServo.attach(servo);

}

void loop() {

  myServo.write(position); 

}
