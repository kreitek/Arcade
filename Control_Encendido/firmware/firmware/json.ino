#include <ArduinoJson.h>


 int getDomoticzValue(byte* json) {
   StaticJsonBuffer<256> jsonBuffer;
  //  DynamicJsonBuffer  jsonBuffer(512);

   JsonObject& root = jsonBuffer.parseObject(json); // "{\"idx\" : 40}"
   if (!root.success()) {
     DEBUGPRINT("parseObject() falló\n");
     return -1;
   }
   //double latitude = root["data"][0];
   if (root["idx"] != DOMOTICZ_IDX){
     return -1; // El mensaje no es para nosotros
   }
   return root["nvalue"];
 }
