int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
byte led = 0x00;
int dt = 100;

void setup() {

  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
}

void loop() {

  led += 1;
  if (led > 0xff){
    led = 0x00;
  }
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,led);
  digitalWrite(latchPin, HIGH);
  delay(dt);
   
}
