
void hardwareSetup(){
  pinMode(PULSADOR, PULSADOR_MODO);
  pinMode(PULSADOR_EXT, PULSADOR_EXT_MODO);

  pinMode(LED_INTERNO, OUTPUT);
  pinMode(RELE, OUTPUT);
  pinMode(RPI_PIN, OUTPUT);
  pinMode(PIN_IO_GND, OUTPUT);

  digitalWrite(LED_INTERNO, LED_INTERNO_OFF);
  digitalWrite(RELE, RELE_OFF);
  digitalWrite(RPI_PIN, LOW);
  digitalWrite(PIN_IO_GND, LOW); // Se usa simplemente como pin GND adicional
}

// Pulsador interior, para modo OTA
void pulsadorOtaLoop(){
  if (digitalRead(PULSADOR) == PULSADOR_PULSADO){ // En cualquier momento puede pasar a modo OTA
    _modo_ota = true;
    otaSetup();
  }
}
