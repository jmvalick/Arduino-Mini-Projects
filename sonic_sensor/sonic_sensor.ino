int trig = 2;
int echo = 3;
float pingTime;

#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int dt1 = 10;
int dt2 = 500;

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(dt1);
  digitalWrite(trig,HIGH);
  delayMicroseconds(dt1);
  digitalWrite(trig,LOW);
  pingTime = pulseIn(echo,HIGH);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pingTime);
  Serial.println(pingTime);
  delay(dt2);
  
}
