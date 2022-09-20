# Sofle keymap from marcoster

This keymap allows has taken some symbol definitions from the klor keyboard and some personal preferences (layer keys on left side, space and enter on the right side).
Also it uses homerow mods and has a separate qwerty layer without those.

## compile for adafruit kb2040 as controler
The following command compiles this for a kb2040 with qmk's **CONVERT_TO** feature (**ALLOW_WARNINGS** is somehow needed for me; never mentioned in documentation).
```
ALLOW_WARNINGS=yes qmk compile -kb sofle -km marcoster -e CONVERT_TO=kb2040
```
