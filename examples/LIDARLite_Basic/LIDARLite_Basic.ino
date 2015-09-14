#include <Wire.h>
#include <LIDARLite_v1.h>

LIDARLite lidar;

void setup(){
  Serial.begin(9600); //Opens serial connection at 9600bps.
  Wire.begin();
}

void loop(){
  Serial.print(lidar.readDistance());
  delay(1000);
}
