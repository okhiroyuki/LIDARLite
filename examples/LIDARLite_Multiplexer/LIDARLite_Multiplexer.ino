#include <Wire.h>
#include <LIDARLite.h>

LIDARLite lidar;

void setup(){
  Serial.begin(115200); //Opens serial connection at 115200bps.     
  Wire.begin();
  lidar.setDelay(15);
}

void loop(){
  Serial.print(lidar.readDistance(0)); // Read Distance from Sensor at Channel 0
  Serial.print(","); // Print "." to separate readings
  Serial.print(lidar.readDistance(1)); // Read Distance from Sensor at Channel 1
  Serial.print(",");  // Print "." to separate readings
  Serial.print(lidar.readDistance(2)); // Read Distance from Sensor at Channel 2
  Serial.print(".");// Print "." to separate readings
  Serial.print(lidar.readDistance(3)); // Read Distance from Sensor at Channel 3
  Serial.println(""); // Add line return
}