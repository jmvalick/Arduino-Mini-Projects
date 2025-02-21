int buzzer = 3;
String state;
int dt = 300;

void setup() {
 
 pinMode(buzzer, OUTPUT);

}

void loop() {

  if (dt == 300){
    state = "up";
  }
  if (dt == 800){
    state = "down";
  }
  if (state == "up"){
    dt += 1;
  }
  if (state == "down"){
    dt -= 1;
  }
  digitalWrite(buzzer, HIGH);
  delayMicroseconds(dt);
  digitalWrite(buzzer, LOW);
  delayMicroseconds(dt);

}
