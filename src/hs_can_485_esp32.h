/*
 * CAN_485.h 
 */

#ifndef HS_CAN_485_ESP32_H_
#define HS_CAN_485_ESP32_H_

#include <Arduino.h>


class HS_CAN_485_ESP32
{
  public:
    HS_CAN_485_ESP32();
    ~HS_CAN_485_ESP32();

    bool begin(int baud);
    bool update(void);
    
  private:
};

extern HS_CAN_485_ESP32 can485;

#endif  /* HS_CAN_485_ESP32 */