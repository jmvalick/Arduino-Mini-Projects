int readPin = A0;
float readValue;
float voltage;
int delayTime = 100;

void setup() {
 
  pinMode(readPin,INPUT);
  Serial.begin(9600);

}

void loop() {
  
  readValue = analogRead(readPin);
  voltage = (5./1023.) * readValue; //5V = 1023
  Serial.println(voltage); 

  delay(delayTime);

}
