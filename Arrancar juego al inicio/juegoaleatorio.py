#!/usr/bin/python
# -*- coding: utf-8 -*-

from os import listdir
from random import shuffle

rutaroms = "/home/pi/RetroPie/roms/mame-mame4all/"

roms = []
for rom in listdir(rutaroms):
    if rom[-3:] == 'zip':
        roms.append(rom)

shuffle(roms)

print("{}{}".format(rutaroms, roms[0]))
