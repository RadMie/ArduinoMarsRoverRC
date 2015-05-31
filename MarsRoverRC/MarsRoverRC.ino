#include <SPI.h>
#include <EEPROM.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include "timers.h"
#include "motors.h"
#include "nrf24.h"
#include "servos.h"

#define DEBUG

Timers<10> timer;

void setup() {
  
#if defined(DEBUG)
  Serial.begin(115200);
#endif



}

void loop() {
  
  
#if defined(DEBUG)
  Serial.print("test");
#endif
}
