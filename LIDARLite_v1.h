#ifndef LIDARLite_v1_h
#define LIDARLite_v1_h

class LIDARLite
{
  public:
    // void constructor
    LIDARLite();
    LIDARLite(int version);
    void setDelay(int delay_time);
    void selectMultiplexerChannel(int channel);
    int readDistance();

  private:
    static const int LIDARLite_ADDRESS_ = 0x62; // Default I2C Address of LIDAR-Lite.
    static const int RegisterMeasure_   = 0x00; // Register to write to initiate ranging.
    static const int MeasureValue_      = 0x04; // Value to initiate ranging.
    static const int RegisterHighLowB_  = 0x8f; // Register to get both High and Low bytes in 1 call.
    static const int I2CMultiplexer_    = 0x70; // PCA9544A Multiplexer Address

    int delay_;
    int version_;
};
#endif
