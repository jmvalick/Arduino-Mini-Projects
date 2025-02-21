 int trig = 2;
int echo = 3;
float pingTime;
float distance;

#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int button = A4;
int buttonVal;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int dt1 = 10;
int dt2 = 100;

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(button,INPUT);
  digitalWrite(button,HIGH);

}

void loop() {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press button to");
  lcd.setCursor(4,1);
  lcd.print("measure");
  buttonVal = digitalRead(button);
  
  while(buttonVal == 1){
    buttonVal = digitalRead(button);
  }
  
  digitalWrite(trig,LOW);
  delayMicroseconds(dt1);
  digitalWrite(trig,HIGH);
  delayMicroseconds(dt1);
  digitalWrite(trig,LOW);
  pingTime = pulseIn(echo,HIGH);
  distance = (0.0134992 * pingTime)/2;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(distance);
  lcd.print(" inches");
  while(buttonVal == 0){
    buttonVal = digitalRead(button);
  } 
}
