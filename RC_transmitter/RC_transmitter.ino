#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7,8); // CE, CSN
const byte address[6] = "00001";

int X1pin = A0;
int Y1pin = A1;
int X2pin = A2;
int Y2pin = A3;
int X1val;
int Y1val;
int X2val;
int Y2val;
int arrayVal[2];

void setup() {
  
  pinMode(X1pin, INPUT);
  pinMode(Y1pin, INPUT);
  pinMode(X2pin, INPUT);
  pinMode(Y2pin, INPUT);
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

}

void loop() {
  
    X1val = analogRead(X1pin);
    Y2val = analogRead(Y2pin);
    arrayVal[0] = X1val;
    arrayVal[1] = Y2val;

    radio.write(&arrayVal, sizeof(arrayVal));

    Serial.println(arrayVal[0]);
    delay(5);
}
