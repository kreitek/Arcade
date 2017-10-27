
void imAliveLoop(){
  // pequeño parpadeo cada x seg para indicar que sigue funcionando
  static unsigned long im_alive_time = 0;
  static bool onoroff = false; // empieza apagado

  if (millis() > im_alive_time){
    if (onoroff){
      digitalWrite(LED_INT, LED_INT_OFF);
      im_alive_time = millis() + 8000;
      onoroff = false;
    }
    else{
      digitalWrite(LED_INT, LED_INT_ON);
      im_alive_time = millis() + 150;
      onoroff = true;
    }
  }
}

void blinkLoop(){
  // parpadeo
  static unsigned long blink_time = 0;
  if (millis() > blink_time){
    digitalWrite(LED_INT, !digitalRead(LED_INT));
    blink_time = millis() + 500;
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
        digitalWrite(LED_INT, !digitalRead(LED_INT));
        while (digitalRead(PULSADOR_EXT) == PULSADOR_EXT_PULSADO) // Espera a soltar el PULSADOR_INT par reiniciar
          delay(50);
        ESP.restart();
      }
    }
  }
  else
    resetflag = false;
}
