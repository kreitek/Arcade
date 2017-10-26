unsigned long _rpi_rele_off_time = 0;
bool  _pdte_apagar = false;

void rpiLoop(){
  if (digitalRead(PULSADOR_EXT) == PULSADOR_EXT_PULSADO)
    rpiConmutar();

  // Corta corriente si ya paso tiempo para apagado seguro
  if (_pdte_apagar)
    if (millis() > _rpi_rele_off_time){
      digitalWrite(RELE, RELE_OFF);
      _pdte_apagar = false;
    }
}

void rpiConmutar(){
  static bool encendido = false; // al arrancar comienza apagado (rele off)
  static unsigned long antirrebotes = 0;
  if (millis() < antirrebotes)
    return;
  if (encendido){
    antirrebotes = millis() + RPI_TIEMPO_APAGADO;
    encendido = false;
    rpiApagar();
  }
  else{
    antirrebotes = millis() + RPI_TIEMPO_ENCENDIDO;
    encendido = true;
    rpiEncender();
  }
}

void rpiEncender(){
  digitalWrite(RPI_PIN, HIGH);
  digitalWrite(RELE, RELE_ON);
}

void rpiApagar(){
  digitalWrite(RPI_PIN, LOW);
  _rpi_rele_off_time = millis() + RPI_TIEMPO_APAGADO;
  _pdte_apagar = true;
}
