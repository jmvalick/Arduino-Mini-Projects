int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
byte led = 0xf0;
int dt = 500;

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
  //led = led/0x80 + led*2;
  led = led*0x80 + led/2;

}
