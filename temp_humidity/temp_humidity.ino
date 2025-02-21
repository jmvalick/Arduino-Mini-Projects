#include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin,Type);
float humidity;
float tempC;
float tempF;

#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int dt = 500;

void setup() {
  
  Serial.begin(9600);
  HT.begin();
  lcd.begin(16,2);
  delay(dt);

}

void loop() {

  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.println(tempF);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  //lcd.print(tempC);
  //lcd.print("C ");
  lcd.print(tempF);
  lcd.print("F");
  delay(dt);
  
}
