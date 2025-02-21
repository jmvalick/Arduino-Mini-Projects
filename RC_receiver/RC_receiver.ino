#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9,10); // CE, CSN
const byte address[6] = "00001";

int X1val;
int Y1val;
int X2val;
int Y2val;
int arrayVal[2];
int lSpeedPin = 5;
int rSpeedPin = 6;
int dir1 = 3;
int dir2 = 4;
int dir3 = 7;
int dir4 = 8;
int mSpeed;
int lSpeed;
int rSpeed;
int subSpeed;

void setup() {
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(lSpeedPin, OUTPUT);
  pinMode(rSpeedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  if (radio.available()) {
    radio.read(&arrayVal, sizeof(arrayVal));

    X1val = arrayVal[0];
    Y2val = arrayVal[1];
   
    if (X1val < 510){
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    digitalWrite(dir3, LOW);
    digitalWrite(dir4, HIGH);
    mSpeed = -255./512. * X1val + 255.;
  }
  else if (X1val > 517){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    digitalWrite(dir3, HIGH);
    digitalWrite(dir4, LOW);
    mSpeed = 255./512. * X1val - 255.;
  }
  else{
    mSpeed = 0;
  }
  
  
  if(Y2val < 510){
    subSpeed = -255./512. * Y2val + 255.;
    lSpeed = mSpeed - subSpeed;
    rSpeed = mSpeed;
  }
  else if(Y2val > 517){
    subSpeed = 255./512. * Y2val - 255.;
    rSpeed = mSpeed - subSpeed;
    lSpeed = mSpeed;
  }
  else{
    lSpeed = mSpeed;
    rSpeed = mSpeed;
  }
  
 
  if(lSpeed < 0){
      lSpeed = 0;
    }
  if(rSpeed < 0){
      rSpeed = 0;
    }
  if(lSpeed < 0){
      lSpeed = 0;
    }
  if(rSpeed > 250){
      rSpeed = 250;
    }
  if(lSpeed > 250){
      lSpeed = 250;
    }

  analogWrite(lSpeedPin, lSpeed);
  analogWrite(rSpeedPin, rSpeed);
  Serial.print(lSpeed);
  Serial.print("   ");
  Serial.println(rSpeed);
  }

}
