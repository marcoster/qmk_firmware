#pragma once

//#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
//
#define WAIT_FOR_USB 1

#define MASTER_RIGHT

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

//#define SPLIT_POINTING_ENABLE
//#define POINTING_DEVICE_LEFT
////#define CIRQUE_PINNACLE_ADDR 0x2A
////#define CIRQUE_PINNACLE_SPI_CS_PIN 


#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_DISABLE_SMOOTHING
//#define CIRQUE_PINNACLE_DISABLE_TAP
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define CIRQUE_PINNACLE_ENABLE_CURSOR_GLIDE
#define CIRQUE_PINNACLE_ENABLE_CIRCULAR_SCROLL
#define CIRQUE_PINNACLE_DIAMETER_MM 35
