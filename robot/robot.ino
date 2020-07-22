#include <SoftwareSerial.h>

//Pins of motor 1
#define mpin00 5
#define mpin01 6

//Pins of motor 2
#define mpin10 3
#define mpin11 11

String command;
int value;

//SoftwareSerial mySerial(2,3); //RX, TX

void setup() {
  digitalWrite(mpin00,0);
  digitalWrite(mpin01,0);
  digitalWrite(mpin10,0);
  digitalWrite(mpin11,0);

  pinMode(mpin00,OUTPUT);
  pinMode(mpin01,OUTPUT);
  pinMode(mpin10,OUTPUT);
  pinMode(mpin11,OUTPUT);

  //mySerial.begin(9600);
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if(Serial1.available()){
  //while(mySerial.available()){
    //command = mySerial.readStringUntil('\n');
    command = Serial1.read();

    value = (command.toInt());

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

      case 5:
        stopRobot();
        break;
    }
  }
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
