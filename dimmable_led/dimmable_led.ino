int readPin = A0;
float voltage;
float ledV;
int LED = 3;
int delayTime = 100;

void setup() {
 
  pinMode(readPin,INPUT);
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

}

void loop() {
  
  float readValue = analogRead(readPin);
  voltage = (5./1023.) * readValue; //5V = 1023
  Serial.println(voltage); 

  ledV = (85./341.) * readValue;
  analogWrite(LED,ledV);

  delay(delayTime);

}
