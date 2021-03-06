#include <Arduino.h>
#include "DFRobot_Heartrate.h"

#define heartRatePin 35

DFRobot_Heartrate heartrate(DIGITAL_MODE); ///< ANALOG_MODE or DIGITAL_MODE

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  uint8_t rateValue;
  heartrate.getValue(heartRatePin); 
  rateValue = heartrate.analogGetRate();  ///< Get heart rate value
  if (rateValue)
  {
    Serial.println(rateValue);
  }
  delay(20);
}
