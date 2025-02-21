#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
float num1;
float num2;
String Operator;
float answer;
int dt = 5000;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  
  lcd.begin(16,2);
  Serial.begin(9600);

}

void loop() {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("First number:");

  while (!Serial.available()){}
  num1 = Serial.parseFloat();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Operator:");
  lcd.setCursor(0,1);
  lcd.print(num1);

  while (!Serial.available()){}
  Operator = Serial.readString();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Second number:");
  lcd.setCursor(0,1);
  lcd.print(num1+Operator);

  while (!Serial.available()){}
  num2 = Serial.parseFloat();
  lcd.clear();
  
  if(Operator == "+"){
    answer = num1 + num2;
  }
  if(Operator == "-"){
    answer = num1 - num2;
  }
  if(Operator == "*"){
    answer = num1 * num2;
  }
  if(Operator == "/"){
    answer = num1 / num2;
  }
  
  lcd.setCursor(0,0);
  lcd.print(num1+Operator+num2+"=");
  lcd.setCursor(0,1);
  lcd.print(answer);
  delay(dt);
  
}
