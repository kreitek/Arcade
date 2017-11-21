unsigned long _rpi_rele_off_time = 0;
bool _pdte_apagar = false;
bool _estado_rpi = false; // al arrancar comienza apagado (rele off)

void rpiLoop(){
  if (digitalRead(PULSADOR_EXT) == PULSADOR_EXT_PULSADO)
    rpiConmutar();

  // Corta corriente si ya paso tiempo para apagado seguro
  if (_pdte_apagar)
    if (millis() > _rpi_rele_off_time){
      digitalWrite(RELE, RELE_OFF);
      digitalWrite(RPI_PIN, HIGH);
      _pdte_apagar = false;
    }
}

void rpiEncender(){
  if (_estado_rpi == false)
    rpiConmutar();
}

void rpiApagar(){
  if (_estado_rpi == true)
    rpiConmutar();
}

void rpiConmutar(){
  static unsigned long antirrebotes = 0;
  if (millis() < antirrebotes)
    return;
  if (_estado_rpi){
    antirrebotes = millis() + RPI_TIEMPO_APAGADO;
    _estado_rpi = false;
    digitalWrite(RPI_PIN, LOW);
    _rpi_rele_off_time = millis() + RPI_TIEMPO_APAGADO;
    _pdte_apagar = true;
  }
  else{
    antirrebotes = millis() + RPI_TIEMPO_ENCENDIDO;
    _estado_rpi = true;
    digitalWrite(RPI_PIN, HIGH);
    digitalWrite(RELE, RELE_ON);
  }
  #ifdef DOMOTICZ_IDX
    mqttSendState();
  #endif
}

bool getEstadoRpi(){
  return _estado_rpi ? 1 : 0;
}
