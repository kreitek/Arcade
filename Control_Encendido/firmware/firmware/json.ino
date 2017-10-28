#include <ArduinoJson.h>

 // StaticJsonBuffer<512> jsonBuffer;
 DynamicJsonBuffer  jsonBuffer(512);

 int getDomoticzValue(byte* json) {
   JsonObject& root = jsonBuffer.parseObject(json); // "{\"idx\" : 40}"
   if (!root.success()) {
     Serial.println("parseObject() failed");
     return -1;
   }
   //double latitude = root["data"][0];
   if (root["idx"] != DOMOTICZ_IDX){
     return -1; // El mensaje no es para nosotros
   }
   return root["nvalue"];
 }
