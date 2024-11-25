WebSocketsServer webSocket = WebSocketsServer(80);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

        // send message to client
        webSocket.sendTXT(num, "Connected");
            }
            break;
        case WStype_TEXT:
            /*if(length > 0)
              lastText = (const char*)payload;
            else
              lastText = "";*/
            break;
        case WStype_BIN:
            if(length == 1)
            {
              microsPerPixel = int(*(const char*)payload) * 10;
            }
            else if(length > 1)
            {
              if(maxSegments * 2 < length) length = maxSegments * 2;
              for(int i = 0; i <  length; i+= 2)
              {					
                lineSegments[i >> 1][0] = ((const char*)payload)[i];
                lineSegments[i >> 1][1] = ((const char*)payload)[i + 1];
                //Serial.printf("segment %d %d\n", lineSegments[i][0], lineSegments[i][1]);
              }
              segmentCount = length / 2;
              //Serial.printf("segments %d\n", segmentCount);
            }
            break;
    case WStype_ERROR:      
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
      break;
    }
}

void setupWebsocket()
{
  //Serial.println(WiFi.localIP());
	webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}
void loopWebsocket()
{
	webSocket.loop();
}