#include "Arduino.h"
#include "motors.h"

Motors::Motors(uint8_t RightEN, uint8_t RightDirBackward, uint8_t RightDirForward, uint8_t LeftEN, uint8_t LeftDirForward, uint8_t LeftDirBackward, uint8_t RightCurrent, uint8_t LeftCurrent, uint8_t RightPWM, uint8_t LeftPWM)
{
  pinMode(RightEN, OUTPUT);
  pinMode(RightDirBackward, OUTPUT);
  pinMode(RightDirForward, OUTPUT);
  
  pinMode(LeftEN, OUTPUT);
  pinMode(LeftDirForward, OUTPUT);
  pinMode(LeftDirBackward, OUTPUT);
  
  _RightEN = RightEN;
  _RightDirBackward = RightDirBackward;
  _RightDirForward = RightDirForward;
  
  _LeftEN = LeftEN;
  _LeftDirForward = LeftDirForward;
  _LeftDirBackward = LeftDirBackward;
  
  _RightCurrent = RightCurrent;
  _LeftCurrent = LeftCurrent;
  
  _RightPWM = RightPWM;
  _LeftPWM = LeftPWM;
}

void Motors::enable(){
  
  digitalWrite(_RightEN, HIGH);
  digitalWrite(_LeftEN, HIGH);
}

void Motors::disable(){
  
  digitalWrite(_RightEN, LOW);
  digitalWrite(_LeftEN, LOW);
}

void Motors::forward(uint8_t powerRight, uint8_t powerLeft) {
  
  digitalWrite(_RightDirForward, HIGH);
  digitalWrite(_LeftDirForward, HIGH);
  
  digitalWrite(_RightDirBackward, LOW);
  digitalWrite(_LeftDirBackward, LOW);
  
  analogWrite(_RightPWM, powerRight);
  analogWrite(_LeftPWM, powerLeft);
}

void Motors::backward(uint8_t powerRight, uint8_t powerLeft) {
  
  digitalWrite(_RightDirForward, LOW);
  digitalWrite(_LeftDirForward, LOW);
  
  digitalWrite(_RightDirBackward, HIGH);
  digitalWrite(_LeftDirBackward, HIGH);
  
  analogWrite(_RightPWM, powerRight);
  analogWrite(_LeftPWM, powerLeft);
}

float Motors::readCurrentRight() {
  
  return analogRead(_RightCurrent) * (38.5 / 1023.0);
}

float Motors::readCurrentLeft() {
  
  return analogRead(_LeftCurrent) * (38.5 / 1023.0);
}
