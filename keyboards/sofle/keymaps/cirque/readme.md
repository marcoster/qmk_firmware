# Sofle keymap from marcoster with cirque trackpad

This keymap allows has taken some symbol definitions from the klor keyboard and some personal preferences (layer keys on left side, space and enter on the right side).
Also it uses homerow mods and has a separate qwerty layer without those.

## Warnings
This is configured to have the cirque trackpad mounted to the right half **AND** to use the right half as main.
On the secondary / left side the default keymap had to be used somehow - this still needs investigation...
And the secondary tap did not work initially (with the 35mm trackpad).

## compile for adafruit kb2040 as controler
The following command compiles this for a kb2040 with qmk's **CONVERT_TO** feature (**ALLOW_WARNINGS** is somehow needed for me; never mentioned in documentation).
```
ALLOW_WARNINGS=yes qmk compile -kb sofle -km marcoster -e CONVERT_TO=kb2040
```
