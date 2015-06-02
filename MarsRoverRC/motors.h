#ifndef motors_h
#define motors_h

#include "Arduino.h"

class Motors
{
  public:
    Motors(uint8_t RightEN, uint8_t RightDirBackward, uint8_t RightDirForward, uint8_t LeftEN, uint8_t LeftDirForward, uint8_t LeftDirBackward, uint8_t RightCurrent, uint8_t LeftCurrent, uint8_t RightPWM, uint8_t LeftPWM);
    void enable();
    void disable();
    void forward(uint8_t powerRight, uint8_t powerLeft);
    void backward(uint8_t powerRight, uint8_t powerLeft);
    float readCurrentRight();
    float readCurrentLeft();
  private:
    uint8_t _RightEN;
    uint8_t _RightDirBackward;
    uint8_t _RightDirForward; 
    
    uint8_t _LeftEN;
    uint8_t _LeftDirForward; 
    uint8_t _LeftDirBackward; 
    
    uint8_t _RightCurrent;
    uint8_t _LeftCurrent; 
    
    uint8_t _RightPWM;
    uint8_t _LeftPWM; 
};

#endif


