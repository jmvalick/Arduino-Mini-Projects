int redPin = 9;
int bright1 = 10;
int bright2 = 100;
int bright3 = 255;

void setup() {
  
  pinMode(redPin,OUTPUT);

}

void loop() {
  
  analogWrite(redPin,bright1);  //value 0-255 (0V-5V)
  delay(500);
  analogWrite(redPin,bright2);
  delay(500);
  analogWrite(redPin,bright3);
  delay(500);
  
}
