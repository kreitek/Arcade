// #define MQTT_MAX_PACKET_SIZE 256
#include "config/all.h"

// Renombrar userconfig_example.h a userconfig.h e introducir credenciales allí
const char* ssid = SSID_NAME;
const char* password = SSID_PASWORD;

bool _modo_ota;

void setup() {
  Serial.begin(115200);
  hardwareSetup();
  digitalWrite(LED_INT, LED_INT_ON); // Mantiene encendido hasta que se coneta wifi
  delay(50);
  // Boton pulsado al inicio -> modo OTA
  _modo_ota = digitalRead(PULSADOR_INT) == PULSADOR_INT_PULSADO;

  if (_modo_ota){
    otaSetup();
  }
  else{
    #ifdef DOMOTICZ_IDX
      wifiSetup();
      mqttSetup();
    #endif
    #if DEBUGOUTPUT == DEBUGOUTPUTTELNET
      telnetSetup();
    #endif
    digitalWrite(LED_INT, LED_INT_OFF);
  }
}

void loop() {
  if (_modo_ota){
    loopOTA();
    blinkLoop();
    resetLoop(); // Reinicia si se mantiene pulsado el boton externo mas de x seg
  }
  else {
    #ifdef DOMOTICZ_IDX
      mqttLoop();
    #endif
    #if DEBUGOUTPUT == DEBUGOUTPUTTELNET
      telnetLoop();
    #endif
    imAliveLoop(); // pequeño parpadeo cada x seg para indicar que sigue funcionando
    rpiLoop();
    resetLoop(); // Reinicia si se mantiene pulsado el boton externo mas de x seg
    PulsadorOtaLoop(); // Este loop al final de este bloque (si PULSADOR_INT -> modo OTA)
  }
  delay(20);
}
