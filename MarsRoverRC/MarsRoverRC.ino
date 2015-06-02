#include <SPI.h>
#include <Wire.h>
#include <VirtualWire.h>
#include "timers.h"
#include "motors.h"
#include "servos.h"

#define DEBUG

Motors motors = Motors(30,32,34,36,38,40,0,1,2,3);  // RightEN, RightDirBackward, RightDirForward, LeftEN, LeftDirForward, LeftDirBackward, RightCurrent,, LeftCurrent, RightPWM, LeftPWM

void setup() {
  
#if defined(DEBUG)
  Serial.begin(115200);
#endif

  vw_set_tx_pin(12);
  vw_set_rx_pin(11);
  vw_set_ptt_pin(10);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();
  
  motors.enable();
}

uint8_t buf[6];
uint8_t buflen = 6;
int motor = 0;

int right = 0;
int left = 0;

void loop() {
  
if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    //motors.forward(buf[1], buf[1]);
    if(buf[1] > 127) {
      
      motor = map(buf[1],128,255,0,180);
      
      if(motor < 25) motor = 0;
      
      if(buf[2] > 127) {
        right = map(buf[2],128,255,0,motor);
        left = (motor * -1);
      } else {
        left = map(buf[2],127,0,0,motor);
        right = (motor * -1);
      }
      
      motors.forward(motor-right,motor-left);
      
    } else {
      
      motor = map(buf[1],127,0,0,180);
      
      if(motor < 25) motor = 0;
      
      if(buf[2] > 127) {
        right = map(buf[2],128,255,0,motor);
        left = (motor * -1);
      } else {
        left = map(buf[2],127,0,0,motor);
        right = (motor * -1);
      }
      
      motors.backward(motor-right,motor-left);
      
    }
  }
}

