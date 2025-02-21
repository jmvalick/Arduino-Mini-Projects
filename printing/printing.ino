float radius = 2;
float pi = 3.14;
float area;
int delayTime = 100;

void setup() {
 
  Serial.begin(115200);

}

void loop() {
  area = pi*radius*radius;
  Serial.print("Area: ");
  Serial.println(area);
  radius += 1;
  delay(delayTime);

}
