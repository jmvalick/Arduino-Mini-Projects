int myByte = 0x0;
int dt = 500;

void setup() {

  Serial.begin(9600);
 
}

void loop() {

  Serial.print(myByte,BIN);
  Serial.print("  ");
  Serial.print(myByte,HEX);
  Serial.print("  ");
  Serial.println(myByte,DEC);
  myByte += 1;
  delay(dt);
 
}
