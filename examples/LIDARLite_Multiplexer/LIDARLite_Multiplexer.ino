// Using NXP PCA9544A I2C Multiplexer

#include <Wire.h>
#include <LIDARLite_v1.h>

LIDARLite lidar;

void setup(){
  Serial.begin(9600); //Opens serial connection at 9600bps.
  Wire.begin();
  lidar.setDelay(15);
}

void loop(){
  lidar.selectMultiplexerChannel(0);
  Serial.print(lidar.readDistance()); // Read Distance from Sensor at Channel 0
  Serial.print(","); // Print "." to separate readings
  lidar.selectMultiplexerChannel(1);
  Serial.print(lidar.readDistance()); // Read Distance from Sensor at Channel 1
  Serial.print(",");  // Print "." to separate readings
  lidar.selectMultiplexerChannel(2);
  Serial.print(lidar.readDistance()); // Read Distance from Sensor at Channel 2
  Serial.print(".");// Print "." to separate readings
  lidar.selectMultiplexerChannel(3);
  Serial.print(lidar.readDistance()); // Read Distance from Sensor at Channel 3
  Serial.println(""); // Add line return
}
