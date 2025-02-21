#include <Servo.h>

int servo = 9;
int position;
Servo myServo;
int photoPin = A0;
int brightness;

void setup()  {

  pinMode(photoPin, INPUT);
  myServo.attach(servo);
  Serial.begin(9600);
  
}

void loop() {

  brightness = analogRead(photoPin);
  position = (33./104.)*brightness - 80;
  Serial.println(position);
  myServo.write(position);
  
}
