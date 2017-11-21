
void hardwareSetup(){
  pinMode(PULSADOR_INT, PULSADOR_INT_MODO);
  pinMode(PULSADOR_EXT, PULSADOR_EXT_MODO);

  pinMode(LED_INT, OUTPUT);
  pinMode(RELE, OUTPUT);
  pinMode(RPI_PIN, OUTPUT);
  pinMode(PIN_IO_GND, OUTPUT);

  digitalWrite(LED_INT, LED_INT_OFF);
  digitalWrite(RELE, RELE_OFF);
  digitalWrite(RPI_PIN, HIGH);
  digitalWrite(PIN_IO_GND, LOW); // Se usa simplemente como pin GND adicional
}

// PULSADOR_INT interior, para modo OTA
void PulsadorOtaLoop(){
  if (digitalRead(PULSADOR_INT) == PULSADOR_INT_PULSADO){ // En cualquier momento puede pasar a modo OTA
    _modo_ota = true;
    otaSetup();
  }
}
