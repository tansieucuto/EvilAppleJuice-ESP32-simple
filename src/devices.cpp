#include <Arduino.h>
#include "devices.hpp"

void generatePacket(const AppleDevice& device, uint8_t* buffer, size_t& outLength) {
  memset(buffer, 0, 31); // Clear buffer

  if (device.type == APPLE_AUDIO) {
      outLength = 31;
      uint8_t header[] = {0x1e, 0xff, 0x4c, 0x00, 0x07, 0x19, 0x07};
      uint8_t body[]   = {0x20, 0x75, 0xaa, 0x30, 0x01, 0x00, 0x00, 0x45, 0x12, 0x12, 0x12};
      
      memcpy(buffer, header, 7);
      buffer[7] = device.modelId;
      memcpy(buffer + 8, body, 11);
  } 
  else if (device.type == APPLE_ACTION) {
    outLength = 11;
    buffer[0] = 0x0A;
    buffer[1] = 0xFF;
    buffer[2] = 0x4C;
    buffer[3] = 0x00;
    buffer[4] = 0x0F;
    buffer[5] = 0x05;
    buffer[6] = 0xC0;
    
    buffer[7] = device.modelId; 
    buffer[8] = random(256);   
    buffer[9] = random(256);
    buffer[10] = random(256);
  }
}
