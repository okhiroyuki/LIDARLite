#include <Wire.h>
#include <LIDARLite_v1.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

// void constructor
LIDARLite::LIDARLite()
{
  delay_ = 20;
};

void LIDARLite::setDelay(int delay_time){
  delay_ = delay_time;
};

void LIDARLite::selectMultiplexerChannel(int channel){
  int controlRegister = 0x04; // The Control register of the Multiplexer
  controlRegister |= channel; // Bitwise OR controlRegister & channel
  Wire.beginTransmission(I2CMultiplexer_);
  if(channel == 0xFF)  Wire.write(0x00);
  else Wire.write(controlRegister);
  Wire.endTransmission();
}

int LIDARLite::readDistance(){

  int distance;

  Wire.beginTransmission(LIDARLite_ADDRESS_); // transmit to LIDAR-Lite
  Wire.write(RegisterMeasure_); // sets register pointer to  (0x00)
  Wire.write(MeasureValue_); // sets register pointer to  (0x00)
  Wire.endTransmission(); // stop transmitting

  delay(delay_);

  Wire.beginTransmission(LIDARLite_ADDRESS_); // transmit to LIDAR-Lite
  Wire.write(RegisterHighLowB_); // sets register pointer to (0x8f)
  Wire.endTransmission(); // stop transmitting

  delay(delay_); // Wait 20ms for transmit

  Wire.requestFrom((int)LIDARLite_ADDRESS_, 2); // request 2 bytes from LIDAR-Lite

  if(2 <= Wire.available()) // if two bytes were received
  {
    distance = Wire.read(); // receive high byte (overwrites previous reading)
    distance = distance << 8; // shift high byte to be high 8 bits
    distance |= Wire.read(); // receive low byte as lower 8 bits
  }

  return distance;   // Print Sensor Name & Distance
}
