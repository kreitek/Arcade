#include "config/all.h"

// Renombrar userconfig_example.h a userconfig.h e introducir credenciales allí
const char* ssid = SSID_NAME;
const char* password = SSID_PASWORD;

bool _modo_ota;

void setup() {
  Serial.begin(115200);
  hardwareSetup();
  delay(50);
  // Boton pulsado al inicio, modo OTA
  _modo_ota = digitalRead(PULSADOR) == PULSADOR_PULSADO;
  if (_modo_ota) {
    otaSetup();
  }
  else {
    wifiSetup();
  }
}

void loop() {
  if (_modo_ota){
    loopOTA();
    resetLoop(); // Reinicia se se mantiene pulsado el boton externo mas de x seg
  }
  else {
    // TODO cambiar blink por imalive
    blinkLoop();
    rpiLoop();
    resetLoop(); // Reinicia se se mantiene pulsado el boton externo mas de x seg
    pulsadorOtaLoop(); // Este loop al final de este bloque
  }
  delay(20);
}
