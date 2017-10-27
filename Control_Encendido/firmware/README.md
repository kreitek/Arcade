Antes de compilar por primera vez, renombrar firmware/config/userconfig_example.h como userconfig.h y cumplimentar.

En principio para hacer cambios de wifi, ip, idx de domoticz etc hay que reflashear. En el futuro se puede poner un formulario web para cambiar estas cosas.

Funcionamiento:
Al pulsar el boton externo, si esta apagado enciende todo (incluida raspberry), y si esta encendido, manda señal a la raspberry para que se apague, y tras un tiempo, apaga todo.
El botón queda inactivo mientras se esta enciendiendo/apagando

Si se mantiene pulsado el boton externo durante 10 segundos, reinicia el sonoff

El boton interno pasa a modo ota (wifi configurada como AP) al cabo de un tiempo (10 minutos configurables) vuelve a modo normal

Códigos del led:
Fijo:  intentando conectarse a wifi
parpadeo continuo: modo AP (solo para OTA)
breve parpadeo cada 8 segundos: modo normal
