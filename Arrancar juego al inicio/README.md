Para arrancar un juego fijo al inicio, edita el archivo /opt/retropie/configs/all/autostart.sh y añade arriba del todo:

```
/opt/retropie/supplementary/runcommand/runcommand.sh 0 _SYS_ nes ~/RetroPie/roms/nes/NAMEOFROM
```

Para arrancar un juego aleatorio, primero copia el script juegoaleatorio.py en /home/pi/scripts/ y luego modifica el archivo /opt/retropie/configs/all/autostart.sh dejandolo asi:

```
#!/bin/bash
juegodehoy=$(python3 /home/pi/scripts/juegoaleatorio.py 2>&1)
/opt/retropie/supplementary/runcommand/runcommand.sh 0 _SYS_ mame-mame4all $juegodehoy
emulationstation #auto
```

