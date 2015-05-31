#include "Arduino.h"
#include "nrf24.h"

NRF24::NRF24(uint8_t CE, uint8_t CS) : RF24(CE, CS)
{
  
}

void NRF24::init(uint8_t channel, uint8_t PAlevel, uint8_t DataRate, bool AutoAck, uint8_t Retries1, uint8_t Retries2, uint8_t CRC) {
  
  uint8_t addr[5] = {'W','o','l','k','T'};

  begin();                           // Setup and configure rf radio
  setChannel(channel);               // Set the channel
  setPALevel(PAlevel);               // Set PA LOW for this demonstration. We want the radio to be as lossy as possible for this example.
  setDataRate(DataRate);             // Raise the data rate to reduce transmission distance and increase lossiness
  setAutoAck(AutoAck);               // Ensure autoACK is enabled
  setRetries(Retries1,Retries2);     // Optionally, increase the delay between retries. Want the number of auto-retries as high as possible (15)
  setCRCLength(CRC);                 // Set CRC length to 16-bit to ensure quality of data
  openWritingPipe(addr);             // Open the default reading and writing pipe
  openReadingPipe(0,addr);       
  startListening();
  powerUp();
}


