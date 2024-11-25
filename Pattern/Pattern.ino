#include "esp_task_wdt.h"
#include <driver/dac.h>
#include "font.h"

const int triggerPin = 4;
const int microsPerPixel = 1000;

void setup() 
{
  pinMode(triggerPin, OUTPUT);
  dac_output_enable(DAC_CHANNEL_1);
  dac_output_enable(DAC_CHANNEL_2);
  dac_output_voltage(DAC_CHANNEL_1, cursorX);
  dac_output_voltage(DAC_CHANNEL_2, cursorY);
  Serial.begin(115200);
  esp_task_wdt_deinit();
}

void loop()
{
  static float u = 0;
  static float v = 0;
  u += 0.01 * 1;
  v += 0.0005;
  digitalWrite(triggerPin, 1);
  int x1 = sin(2 * u) * 127 + 127;
  int y1 = sin(1 * u + v) * 127 + 127;
  dac_output_voltage(DAC_CHANNEL_1, x1);
  dac_output_voltage(DAC_CHANNEL_2, y1);
  delayMicroseconds(microsPerPixel);
}
