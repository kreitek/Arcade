unsigned long _timepoblink = 0;

void blinkLoop() {
  if (millis() > _timepoblink) {
    digitalWrite(LED_INTERNO, !digitalRead(LED_INTERNO));
    _timepoblink = millis() + 1000;
  }
}

// Reinicia si se mantiene pulsado el boton externo mas de x seg
void resetLoop() {
  static bool resetflag = false;
  static unsigned long resettime = 0;

  if (digitalRead(PULSADOR_EXT) == PULSADOR_EXT_PULSADO) {
    if (!resetflag) {
      resetflag = true;
      resettime = millis() + RESET_DURATION;
    }
    else {
      if (millis() > resettime) {
        digitalWrite(LED_INTERNO, !digitalRead(LED_INTERNO));
        while (digitalRead(PULSADOR_EXT) == PULSADOR_EXT_PULSADO) // Espera a soltar el pulsador par reiniciar
          delay(50);
        ESP.restart();
      }
    }
  }
  else
    resetflag = false;
}
