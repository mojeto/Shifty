#include <Shifty.h>

Shifty::Shifty(byte count) {
  this->byteCount = min(max(byteCount, 1), WRITE_BUFFER);
  this->byteIndex = 0;
}  

void Shifty::setPins(byte dataPin, byte clockPin, byte latchPin) {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  this->dataPin = dataPin;
  this->clockPin = clockPin;
  this->latchPin = latchPin;
}

void Shifty::writeByte(byte value) {
  if(this->byteIndex >= this->byteCount) {
    resetIndex();
  }
  this->writeBuffer[this->byteIndex++] = value;
}

void Shifty::resetIndex() {
  this->byteIndex = 0;
}

void Shifty::flush() {
  writeAllBytes();
  resetIndex();
}

void Shifty::writeAllBytes() {
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  for(byte i = 0; i < this->byteIndex; i++) {
    shiftOut(dataPin, clockPin, MSBFIRST, this->writeBuffer[i]);
  }
  digitalWrite(latchPin, HIGH);
}
