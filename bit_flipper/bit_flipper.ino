int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
byte led = 0b10101010;
int dt = 100;

void setup() {
  
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
}

void loop() {

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,led);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  led = 0xFF - led;
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,led);
  digitalWrite(latchPin, HIGH);

}
