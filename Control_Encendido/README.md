# Proposito

Para el control de encendido utilizamos un sonoff (esp8266). El sonoff ya viene con un pulsador interno, un led y un relé. Le añadimos un pulsador externo (para encender y apagar la maquina) y una salida para la raspberry. Cuando se pulsa el botón externo, alimenta la regleta, lo que enciende todos los sistemas (raspberry pi, monitor, audio).

Cuando se vuelve a pulsar, manda señal a la raspberry para que se apague, espera un tiempo, y corta la regleta. Escucha y emite mensajes MQTT

# Conexiones
| Pin N | Sonoff J1 | Dispositivo | N Pin | Pin desc |
| ------ | ------ | ------ | ------ | ------ |
| 1 | VCC-3V3 | NC | NC | NC |
| 2 | E-RX | X | x | X |
| 3 | E-TX | x | x | X |
| 4 | GND | RPi | 5 | GND |
| 5 | GPIO14 | Pulsador | 1 |  |

