# mask keyboard

[Github KiCad Projects](https://github.com/marcoster/mask)

*mask* keyboards are some (working) experiments built after starting digging into the world of split keyboards.
Each version has a totally different goal/approach.
The basic layout is heavily inspired by the sofle-keyboard (but the encoder was removed, since I did never get used to it).

## mask-0.0.0
Version 0 (not supported in qmk) had 2 goals:
  1) add another column on the outside
    - I thought that would be great, but it's actually better to use more layer ;-)
  2) tinker around with the Nordic nRF5340 based BLE module ublox NORA-B106
    - which worked with some quirks under zmk, but was not that easy at that time (the chip was quite new)
  3) I totally missed adding battery-charger and connectors for a battery for a fully-wireless build...


## mask-1.0.0
Version 1 is a rather normal split keyboard like the sofle. It uses the staggering from sofle-v1 and has full rgb-lighting
(but with proper reverse-mount LEDs (SK6812-E; [Adafruit 4960](https://github.com/marcoster/mask)) which makes this part far
easier to solder.
Switches are Cherry MX with hotswap sockets.
The controller is populated through a standard Pro-Micro socket. In my case I used the KB2040.

### Compile
Depending on your controller, but i.e. for the marcoster keymap:
```
qmk compile -kb mask -km marcoster -e CONVERT_TO=kb2040 # defaults to rev1
or
qmk compile -kb mask/rev1 -km marcoster -e CONVERT_TO=kb2040
```

## mask-2.0.0
Version 2 is the ultra-slim variant using Cherry MX ULP switches. The column-staggering is a bit more extreme than V1 and
the thumb cluster is also different. The controller is also populated by a Pro-Micro pinout, but this time the board has to
be soldered directly to the pcb to stay as slim as possible.
The board is prepared for per-key rgb-lighting, but this was never tested (I never got my hands on the needed LEDs; and it
might get really hard to solder, since the switches have to be placed over the LEDs.

### Compile
```
qmk compile -kb mask/rev2 -km rev2 -e CONVERT_TO=kb2040
```

