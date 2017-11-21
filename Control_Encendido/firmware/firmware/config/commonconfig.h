
#define RESET_DURATION  10 * 1000 // milisegundos que hay que pulsar para resetear
#define RPI_TIEMPO_ENCENDIDO  25 * 1000 // milisegundos que tarda en encender
                                    // medido hasta que funciona el script python de apagar
#define RPI_TIEMPO_APAGADO  20 * 1000 // milisegundos que tarda en apagar, en el peor de los casos ( normalmente 15s)
#define OTA_TIMEOUT 10 * 60 * 1000 // tiempo que mantiene el modo ota (luego reinicia)

#define HEARTBEAT_FREC  15 * 60 * 1000 // frecuencia de mensaje mqtt de heartbeat
