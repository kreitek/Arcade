char bufferprint[500]; // Para imprimir

#define DEBUGOUTPUTSERIAL 1
#define DEBUGOUTPUTTELNET 2

#if DEBUGOUTPUT == DEBUGOUTPUTSERIAL
  #define DEBUGPRINT(...) {sprintf(bufferprint, __VA_ARGS__);Serial.print(bufferprint);}
#elif DEBUGOUTPUT == DEBUGOUTPUTTELNET
  #define DEBUGPRINT(...) {sprintf(bufferprint, __VA_ARGS__);sendTelnet(bufferprint);}
#else
  #define DEBUGPRINT(x)
#endif
