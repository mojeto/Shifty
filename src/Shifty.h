#ifndef Shifty_h
#define Shifty_h

#include <Arduino.h>

const byte WRITE_BUFFER = 4;

class Shifty {
  public:

  Shifty(byte count);

  void setPins(byte dataPin, byte clockPin, byte latchPin);
  void writeByte(byte value);
  void flush();
  void resetIndex();

  private:

  byte dataPin;
  byte clockPin;
  byte latchPin;
  
  byte byteCount;
  byte byteIndex;
  byte writeBuffer[WRITE_BUFFER];
  
  void writeAllBytes();
};

#endif
