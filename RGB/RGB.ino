int red = 9;
int green = 10;
int blue = 11;
String myColor;
String msg = "Enter color: ";

void setup() {
  
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {
 
  Serial.println(msg);
  while (Serial.available() == 0){

  }
  myColor = Serial.readString();
  Serial.println(myColor);

  if (myColor == "red"){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }
  if (myColor == "green"){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
  }
   if (myColor == "blue"){
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
  }
  if (myColor == "yellow"){
    analogWrite(red,255);
    analogWrite(green,150);
    analogWrite(blue,0);
  }
  if (myColor == "purple"){
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,175);
  }
  if (myColor == "orange"){
    analogWrite(red,255);
    analogWrite(green,30);
    analogWrite(blue,0);
  }
  if (myColor == "pink"){
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,30);
  }
  if (myColor == "white"){
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);
  }
  if (myColor == "off"){
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  }

}
