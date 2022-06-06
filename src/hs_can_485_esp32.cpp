#include "HS_ESP32_CAN485.h"

HS_CAN_485_ESP32::HS_CAN_485_ESP32(void)
{
}

HS_CAN_485_ESP32::~HS_CAN_485_ESP32()
{ 
}



void taskUpdate( void *pvParameters );

void taskUpdate(void *pvParameters) 
{
  HS_JOY_ESP32 *p_class =  (HS_CAN_485_ESP32 *)pvParameters;
  
  for (;;)
  {
    p_class->update();
    vTaskDelay(2);
  }
}

bool HS_CAN_485_ESP32::begin(int baud)
{
  driverInit();
  Serial.begin(baud);    

  xTaskCreatePinnedToCore(
    taskUpdate
    ,  "update"
    ,  4*1024   // Stack size
    ,  (void *)this
    ,  1        // Priority
    ,  NULL 
    ,  1);
    
  // disable brownout detector
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  return true;
}


bool HS_CAN_485_ESP32::update(void)
{
  return true;
}
