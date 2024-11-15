// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


#define LCG(kc) LCTL(LGUI(kc)) // left CTL and left GUI modifier
#define LSFT_GRV MT(MOD_LSFT, KC_GRV)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAK,
    KC_GAME,
    KC_GHOME,
    KC_GEND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                             KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
  KC_LSFT,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                             KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,     // no homerow mods
  KC_LCTL, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,     KC_MUTE,       XXXXXXX, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_LCTL, KC_LALT, KC_LGUI, TL_LOWR, TL_UPPR,      KC_ENT,  KC_SPC, KC_RGUI, KC_RALT, KC_RCTL
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,          KC_5,                           KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_F,    KC_P,          KC_B,                           KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_LSFT,  KC_A,   KC_R,     KC_S,    KC_T,          KC_G,                           KC_M,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,     KC_C,    KC_D,          KC_V,     KC_MUTE,     XXXXXXX, KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL,  KC_LALT, KC_LGUI,       TL_LOWR, TL_UPPR,    KC_ENT,  KC_SPC, KC_RGUI, KC_CAPS, KC_RCTL
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX,   LCG(KC_1), LCG(KC_2), LCG(KC_3), LCG(KC_4), LCG(KC_5),                         LCG(KC_6), LCG(KC_7), LCG(KC_8), LCG(KC_9), LCG(KC_0), KC_BSPC,
  KC_TILD,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
  LSFT_GRV,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                           KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_UNDS,
  _______,   KC_EQL,    KC_MINS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   _______,       _______, KC_LBRC,   KC_RBRC,   KC_PIPE,   KC_COLN,   KC_BSLS,   _______,
                        _______,   _______,   _______,   _______,   _______,     _______, _______,   _______,   _______,   _______
),

/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_CAPS, XXXXXXX, KC_UP,   XXXXXXX, KC_VOLU, XXXXXXX,                          KC_PGUP, KC_PGDN, KC_DEL,  KC_INS,  XXXXXXX, KC_F12,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_VOLD, XXXXXXX,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,   _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,                     KC_GHOME,  KC_GEND,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_TOG, RGB_HUI,   RGB_VAI,    RGB_SAI, XXXXXXX,                     KC_QWERTY, KC_COLEMAK, KC_GAME, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_MOD, RGB_HUD,   RGB_VAD,    RGB_SAD, XXXXXXX,                     XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______,   _______,    _______, _______, _______,   _______, _______,   _______,    _______, _______
  ),

/*
 * GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSFT |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  ^   |  M   | LALT |SPACE | /ENTER  /       \RAISE \  |LOWER | RGUI | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                           KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                           KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_ENT,
  KC_LSFT,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                           KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LCTL, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,   KC_MUTE,       XXXXXXX, KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_CIRC,  KC_M,    KC_LALT, KC_SPC, KC_ENT,        TL_UPPR,TL_LOWR, KC_RGUI, KC_RALT, KC_RCTL
),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_GHOME:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_HOME);
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_HOME);
            }
            return false;
        case KC_GEND:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_END);
            } else {
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_END);
            }
            return false;
    }
    return true;
}
