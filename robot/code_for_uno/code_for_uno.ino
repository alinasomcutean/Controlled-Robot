#include <Wire.h>

//Pins of motor 1
#define mpin00 5
#define mpin01 6

//Pins of motor 2
#define mpin10 3
#define mpin11 11

int value = 0;

void setup() {
  digitalWrite(mpin00,0);
  digitalWrite(mpin01,0);
  digitalWrite(mpin10,0);
  digitalWrite(mpin11,0);

  pinMode(mpin00,OUTPUT);
  pinMode(mpin01,OUTPUT);
  pinMode(mpin10,OUTPUT);
  pinMode(mpin11,OUTPUT);

  Serial.begin(9600);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(){
  value = Wire.read();
}

void forward(){
  digitalWrite(mpin00, 1);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 1);
  digitalWrite(mpin11, 0);
}

void back(){
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 1);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 1);
}

void left(){
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 1);
  digitalWrite(mpin11, 0);
}

void right(){
  digitalWrite(mpin00, 1);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
}

void stopRobot(){
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(value){
      case 1:
        forward();
        break;

      case 2:
        back();
        break;
      
      case 3:
        left();
        break;
      
      case 4:
        right();
        break;

      case 0:
        stopRobot();
        break;
    }
}
