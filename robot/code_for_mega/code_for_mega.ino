#include <Wire.h>

String command;
int value;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  //Wire.begin();
}

void loop() {
  if(Serial1.available()){
    command = Serial1.read();
    value = (command.toInt());
    Serial.write(Serial1.read());
    //Wire.beginTransmission(9);
    //Wire.write(value);
    //Wire.endTransmission();
  }
}
