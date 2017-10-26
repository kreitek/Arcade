
#if defined(WEMOS)
  #define PULSADOR      0 // D3 // CUIDADO no todos los pines de weemos tienen pullups
  #define PULSADOR_MODO INPUT_PULLUP
  #define PULSADOR_PULSADO  LOW
  #define LED_INTERNO   BUILTIN_LED
  #define LED_INTERNO_ON   0
  #define LED_INTERNO_OFF   1
  #define RELE          14  //D5
  #define RELE_ON       HIGH
  #define RELE_OFF      LOW
  #define PULSADOR_EXT  15 // D8 resistencia fisica de pulldown
  #define PULSADOR_EXT_MODO INPUT
  #define PULSADOR_EXT_PULSADO  HIGH
  #define RPI_PIN       12 // D6
  #define PIN_IO_GND    D2

#elif defined(SONOFF)
  #define PULSADOR      0
  #define PULSADOR_MODO INPUT  // ya tiene resistencia fisica del pullup
  #define PULSADOR_PULSADO  HIGH
  #define LED_INTERNO   13  // Logica negativa
  #define LED_INTERNO_ON  0
  #define LED_INTERNO_OFF 1
  #define RELE          12
  #define RELE_ON       1
  #define RELE_OFF      0
  #define PULSADOR_EXT  3   // J1 Pin 2 (RDX)
  #define PULSADOR_EXT_MODO INPUT_PULLUP // TODO comprobar que se puede activar pullup serial
  #define PULSADOR_EXT_PULSADO  LOW
  #define RPI_PIN       1   // J1 Pin 3 (TXD)
  #define PIN_IO_GND    14  // J1 Pin 5 (MTMS)

#endif
