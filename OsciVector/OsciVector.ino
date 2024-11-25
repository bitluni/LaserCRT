//Arduino and Events need to run on core 0. core 1 is used realtime for driver timings

#include <WiFi.h>
#include <WebSocketsServer.h>
#include "esp_task_wdt.h"
#include "credentials.h"

#include "esp_task_wdt.h"
#include <driver/dac.h>

int segmentCount = 0;
const int maxSegments = 16000;
uint8_t lineSegments[maxSegments][2];

const int triggerPin = 4;
int microsPerPixel = 2000;

#include "websocket.h"

int cursorX = 128;
int cursorY = 128;

void line(int x1, int y1, int x2, int y2)
{
  int m = max(abs(x1 - x2), abs(y1 - y2));
  if(m <= 2)
  {
    dac_output_voltage(DAC_CHANNEL_1, x1);
    dac_output_voltage(DAC_CHANNEL_2, y1);
    delayMicroseconds(microsPerPixel);
  }
  else
  {
    int x3 = (x1 + x2) >> 1;
    int y3 = (y1 + y2) >> 1;
    line(x1, y1, x3, y3);
    line(x3, y3, x2, y2);
  }
}

void move(int x, int y, int luminance)
{
  if(luminance == 0)
  {
    digitalWrite(triggerPin, 0);
    line(cursorX, cursorY, x, y);

/*    digitalWrite(triggerPin, 0);
    int d = max(abs(x - cursorX), abs(y - cursorY));
    dac_output_voltage(DAC_CHANNEL_1, cursorX);
    dac_output_voltage(DAC_CHANNEL_2, cursorY);
    delayMicroseconds(d * microsPerPixel);*/
  }
  else
  {
    digitalWrite(triggerPin, 1);
    line(cursorX, cursorY, x, y);
    digitalWrite(triggerPin, 0);
  }
  cursorX = x;
  cursorY = y;
}

#include "vectorPrint.h"

void initWifi()
{
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  //WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void wifiTask(void *param = 0)
{
 // while(true)
  {
    loopWebsocket();
    //delay(20);
  }
}

void drawTask(void *param = 0)
{
	//while(true)
	{
    /*move(0,0, 0);
    move(127,0, 1);
    move(127,127, 1);
    move(0,127, 1);
    move(0,0, 1);*/
	  //print(0, 0, "BIT", 50, 100, 4, 4);

    /*for(int i = 1; i < segmentCount; i++)
    {
      if(lineSegments[i - 1][0] != 255 && lineSegments[i][0] != 255)
      {
        digitalWrite(triggerPin, 1);
        line(lineSegments[i - 1][0], lineSegments[i - 1][1], lineSegments[i][0], lineSegments[i][1]);
        digitalWrite(triggerPin, 0);
      }
        //Serial.printf("line %d %d %d %d\n", lineSegments[i - 1][0], lineSegments[i - 1][1], lineSegments[i][0], lineSegments[i][1]);

    }    */

    bool restart = true;
    for(int i = 0; i < segmentCount; i++)
      {
        if(lineSegments[i][0] == 255)
          restart = true;    
        else
        {
          int x = lineSegments[i][0];
          int y = lineSegments[i][1];
          if(!restart)
            move(x, y, 1);
          else
            move(x, y, 0);
          restart = false;
        }
      }
    //delay(10);
	}
}

void setup() 
{
  esp_task_wdt_deinit();
  Serial.begin(115200);
  initWifi();
  setupWebsocket();
  pinMode(triggerPin, OUTPUT);
  dac_output_enable(DAC_CHANNEL_1);
  dac_output_enable(DAC_CHANNEL_2);
  dac_output_voltage(DAC_CHANNEL_1, cursorX);
  dac_output_voltage(DAC_CHANNEL_2, cursorY);

  TaskHandle_t xHandle = NULL;
  //xTaskCreatePinnedToCore(drawTask, "draw", 2000, 0,  ( 2 | portPRIVILEGE_BIT ), &xHandle, 1);
  //xTaskCreatePinnedToCore(wifiTask, "wifiStuff", 20000, 0,  ( 2 | portPRIVILEGE_BIT ), &xHandle, 0);  
}

void loop()
{
  drawTask();
  wifiTask();
}
