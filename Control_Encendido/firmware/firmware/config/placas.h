
#if defined(WEMOS)
  #define PULSADOR_INT      0 // D3 // CUIDADO no todos los pines de weemos tienen pullups
  #define PULSADOR_INT_MODO INPUT_PULLUP
  #define PULSADOR_INT_PULSADO  LOW
  #define LED_INT   BUILTIN_LED
  #define LED_INT_ON   0
  #define LED_INT_OFF   1
  #define RELE          14  //D5
  #define RELE_ON       HIGH
  #define RELE_OFF      LOW
  #define PULSADOR_EXT  15 // D8 resistencia fisica de pulldown
  #define PULSADOR_EXT_MODO INPUT
  #define PULSADOR_EXT_PULSADO  HIGH
  #define RPI_PIN       12 // D6
  #define PIN_IO_GND    D2

#elif defined(SONOFF)
  #define PULSADOR_INT      0 //PULSADOR_INT interno del sonoff
  #define PULSADOR_INT_MODO INPUT  // ya tiene resistencia fisica del pullup
  #define PULSADOR_INT_PULSADO  LOW
  #define LED_INT         13
  #define LED_INT_ON      0
  #define LED_INT_OFF     1
  #define RELE            12
  #define RELE_ON         1
  #define RELE_OFF        0
  #define PULSADOR_EXT    14  // J1 Pin 5 (MTMS) (admite pullup) (gris)
  #define PULSADOR_EXT_MODO INPUT_PULLUP
  #define PULSADOR_EXT_PULSADO  LOW
  #define RPI_PIN         3   // J1 Pin 2 (RDX) (verde)
  #define PIN_IO_GND      1   // J1 Pin 3 (TXD) (azul)
  // J1 Pin 4 GND
  // J1 Pin 1 3,3v
  // NOTA no cambiar pines, porque otras convinaciones dan problemas

  #endif
