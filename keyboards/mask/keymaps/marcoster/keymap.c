/* Copyright 2023 Marco Sterbik (@marcoster)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LCG(kc) LCTL(LGUI(kc)) // left CTL and left GUI modifier
#define LSFT_GRV MT(MOD_LSFT, KC_GRV)

enum taipo_mod {
    TAIPO_MOD_NONE,
    TAIPO_MOD_LOWER,
    TAIPO_MOD_RAISE,
};

enum mask_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _QWERTY_HOMEROW,
    _TAIPO,
    _TAIPO_LOWER,
    _TAIPO_RAISE,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE, KC_QWERTY_HOMEROW, KC_TAIPO, KC_GAME, KC_LOWER, KC_RAISE, KC_ADJUST, KC_GHOME, KC_GEND, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE};

// MOD TAP helper
#define MT_A LCTL_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_J RSFT_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_SCLN RCTL_T(KC_SCLN)

#define MT_TAIPO_LOWER LT(_TAIPO_LOWER, KC_BSPC)
#define MT_TAIPO_RAISE LT(_TAIPO_RAISE, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSFT |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LGUI |LOWER | /RAISE  /       \ENTER \  |SPACE | RGUI | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */


[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                                    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
  KC_LSFT,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                                    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,     // no homerow mods
  KC_LCTL, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,     KC_MUTE,       QK_COMBO_TOGGLE, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_RAISE,      KC_ENT,          KC_SPC, KC_RGUI, KC_RALT, KC_RCTL
),
[_QWERTY_HOMEROW] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                                    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
  KC_LSFT,  MT_A,   MT_S,     MT_D,    MT_F,   KC_G,                                     KC_H,   MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,     // with homerow mods
  KC_LCTL,  KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,     KC_MUTE,      QK_COMBO_TOGGLE, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_RAISE,      KC_ENT,          KC_SPC, KC_RGUI, KC_RALT, KC_RCTL
),
/*
 * TAIPO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSFT |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  | RSFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LGUI |LOWER | /RAISE  /       \ENTER \  |SPACE | RGUI | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_TAIPO] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_GHOME,       KC_GEND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_QWERTY,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_R,    KC_S,     KC_N,    KC_I,   XXXXXXX,                                         XXXXXXX,        KC_I,    KC_N,    KC_S,    KC_R,    XXXXXXX,
  XXXXXXX, KC_A,    KC_O,     KC_T,    KC_E,   XXXXXXX,        KC_MUTE,        QK_COMBO_TOGGLE, XXXXXXX,        KC_E,    KC_T,    KC_O,    KC_A,    XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, MT_TAIPO_LOWER, MT_TAIPO_RAISE, MT_TAIPO_RAISE,  MT_TAIPO_LOWER, XXXXXXX, XXXXXXX, XXXXXXX
),
[_TAIPO_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_GHOME,  KC_GEND,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_QWERTY, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX, LSFT(KC_R), LSFT(KC_S), LSFT(KC_N), LSFT(KC_I), XXXXXXX,                            XXXXXXX,   LSFT(KC_I), LSFT(KC_N), LSFT(KC_S), LSFT(KC_R), XXXXXXX,
  XXXXXXX, LSFT(KC_A), LSFT(KC_O), LSFT(KC_T), LSFT(KC_E), XXXXXXX, KC_MUTE,  QK_COMBO_TOGGLE, XXXXXXX,   LSFT(KC_E), LSFT(KC_T), LSFT(KC_O), LSFT(KC_A), XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX,    KC_TRNS, KC_TRNS,  KC_TRNS,         KC_TRNS,   XXXXXXX,    XXXXXXX,    XXXXXXX
),
[_TAIPO_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  KC_GHOME,  KC_GEND, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_RABK, KC_RCBR, KC_RBRC, KC_RPRN, XXXXXXX,                                  XXXXXXX,   KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, XXXXXXX,
  XXXXXXX, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX, KC_MUTE,        QK_COMBO_TOGGLE, XXXXXXX,   KC_LPRN, KC_LBRC, KC_LCBR, KC_LABK, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS,        KC_TRNS,         KC_TRNS,   XXXXXXX, XXXXXXX, XXXXXXX
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
  KC_LCTL, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,   KC_MUTE,       XXXXXXX,  KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                    KC_CIRC,  KC_M,    KC_LALT, KC_SPC, KC_ENT,        KC_RAISE,KC_LOWER, KC_RGUI, KC_RALT, KC_RCTL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC | // numbers moded with CTRL and GUI
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |  _   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | LSFT |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   |  |   :  |   \  | RSFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LGUI |      | /ADJUST /       \ENTER \  |SPACE | RGUI | RALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX,   LCG(KC_1), LCG(KC_2), LCG(KC_3), LCG(KC_4), LCG(KC_5),                         LCG(KC_6), LCG(KC_7), LCG(KC_8), LCG(KC_9), LCG(KC_0), KC_BSPC,
  KC_TILD,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                              KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
  LSFT_GRV,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                           KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_UNDS,
  _______,   KC_EQL,    KC_MINS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   _______,       _______, KC_LBRC,   KC_RBRC,   KC_PIPE,   KC_COLN,   KC_BSLS,   _______,
                        _______,   _______,   _______,   _______,   KC_ADJUST,     _______, _______,   _______,   _______,   _______
),


/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    | F6   |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |  UP  |      | VOLU |      |                    | PGUP | PGDN | DEL  | INS  |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LEFT | DOWN |RIGHT | VOLD |      |-------.    ,-------| LEFT | DOWN | UP   | RIGHT| HOME | END  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      | MUTE |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |ADJUST| /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_CAPS, XXXXXXX, KC_UP,   XXXXXXX, KC_VOLU, XXXXXXX,                          KC_PGUP, KC_PGDN, KC_DEL,  KC_INS,  XXXXXXX, KC_F12,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_VOLD, XXXXXXX,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,   _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, KC_ADJUST, _______,      _______, _______, _______, _______, _______
),


/* ADJUST | RGB COMMANDS              |
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT |      |      |      |      |      |                    |LG+HOME|LG+END|      |      |      |      |
 * |------+------+------+------+------+------|                    |-------+------+------+------+------+------|
 * |      |TOGGLE| HUI  | VAI  | SAI  |      |                    |QWERTY | COLEM| GAME |QW_HR |      |      |
 * |------+------+------+------+------+------|                    |-------+------+------+------+------+------|
 * |      | MOD  | HUD  | VAD  | SAD  |      |-------.    ,-------|       |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |-------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|       |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,                     KC_GHOME,  KC_GEND,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_TOG, RGB_HUI,   RGB_VAI,    RGB_SAI, XXXXXXX,                     KC_QWERTY, KC_TAIPO, KC_GAME, KC_QWERTY_HOMEROW, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_MOD, RGB_HUD,   RGB_VAD,    RGB_SAD, XXXXXXX,                     XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______,   _______,    _______, _______, _______,   _______, _______,   _______,    _______, _______
  )
};


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}
// clang-format on

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _TAIPO:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _TAIPO:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
/*
#define TP_SINGLE_HANDLE_CHAR(key, kc_raise)    case key: {                                 \
                                                    switch(get_highest_layer(layer_state)) {                   \
                                                        case TAIPO_MOD_LOWER:               \
                                                            if (record->event.pressed) {    \
                                                                tap_code16(LSFT(key));      \
                                                            }                               \
                                                            return false;                   \
                                                        case TAIPO_MOD_RAISE:               \
                                                            if (record->event.pressed) {    \
                                                                tap_code16(kc_raise);       \
                                                            }                               \
                                                            return false;                   \
                                                        default:                            \
                                                            break;                          \
                                                    }                                       \
                                                    return true;                            \
                                                }

*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //TP_SINGLE_HANDLE_CHAR(KC_R, KC_RABK)
        //TP_SINGLE_HANDLE_CHAR(KC_S, KC_RCBR)
        //TP_SINGLE_HANDLE_CHAR(KC_N, KC_RBRC)
        //TP_SINGLE_HANDLE_CHAR(KC_I, KC_RPRN)

        //TP_SINGLE_HANDLE_CHAR(KC_A, KC_LABK)
        //TP_SINGLE_HANDLE_CHAR(KC_O, KC_LCBR)
        //TP_SINGLE_HANDLE_CHAR(KC_T, KC_LBRC)
        //TP_SINGLE_HANDLE_CHAR(KC_E, KC_LPRN)

        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_QWERTY_HOMEROW:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY_HOMEROW);
            }
            return false;

        case KC_TAIPO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_TAIPO);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
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

        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

// void keyboard_post_init_user(void) {
//     debug_enable   = true;
//     debug_matrix   = false;
//     debug_keyboard = true;
//     debug_mouse    = false;
// }


//---- TAIPO COMBOS ----//
#define TP_COMBO_DEF(name, key1, key2) const uint16_t PROGMEM name##_combo[] = {key1, key2, COMBO_END};
#define TP_COMBO_DEF3(name, key1, key2, key3) const uint16_t PROGMEM name##_combo[] = {key1, key2, key3, COMBO_END};
#define TP_COMBO_ACTION(name) [name] = COMBO_ACTION(name##_combo)
#define TP_COMBO_MOD_HANDLE(name, kc_none, kc_lower, kc_raise)      case name: {                            \
                                                                        if (pressed) {                      \
                                                                            switch(get_highest_layer(layer_state)) {     \
                                                                                case _TAIPO_LOWER:       \
                                                                                    tap_code16(kc_lower);   \
                                                                                    break;                  \
                                                                                case _TAIPO_RAISE:       \
                                                                                    tap_code16(kc_raise);   \
                                                                                    break;                  \
                                                                                case TAIPO_MOD_NONE:        \
                                                                                default:                    \
                                                                                    tap_code16(kc_none);    \
                                                                                    break;                  \
                                                                            };                              \
                                                                        }                                   \
                                                                    }                                       \
                                                                    break;

#define TP_COMBO_MOD_HANDLE_CHAR(name, kc_none, kc_raise) TP_COMBO_MOD_HANDLE(name, kc_none, LSFT(kc_none), kc_raise)
#define TP_COMBO_MOD_HANDLE_OSM(name, kc_none, kc_lower, kc_raise)  case name: {                            \
                                                                        if (pressed) {                      \
                                                                            switch(get_highest_layer(layer_state)) {           \
                                                                                case _TAIPO_LOWER:       \
                                                                                    tap_code16(kc_lower);   \
                                                                                    break;                  \
                                                                                case _TAIPO_RAISE:       \
                                                                                    tap_code16(kc_raise);   \
                                                                                    break;                  \
                                                                                case TAIPO_MOD_NONE:        \
                                                                                default:                    \
                                                                                    set_oneshot_mods(MOD_BIT(kc_none));    \
                                                                                    break;                  \
                                                                            };                              \
                                                                        }                                   \
                                                                    }                                       \
                                                                    break;




enum combos {
    TP_RS,
    TP_NI,
    TP_AO,
    TP_TE,

    TP_OT,
    TP_SN,
    TP_AE,
    TP_RI,
    TP_RN,
    TP_SI,
    TP_AT,
    TP_OE,
    TP_RT,
    TP_OI,
    TP_SE,
    TP_AN,
    TP_RE,
    TP_AI,
    TP_ST,
    TP_ON,
    TP_RO,
    TP_TI,
    TP_NE,
    TP_AS,

    TP_RA,
    TP_SO,
    TP_NT,
    TP_IE,
    TP_SNI,
    TP_OTE,
    TP_COMBO_LEN,
};
uint16_t COMBO_LEN = TP_COMBO_LEN;

TP_COMBO_DEF(TP_RS, KC_R, KC_S);
TP_COMBO_DEF(TP_NI, KC_N, KC_I);
TP_COMBO_DEF(TP_AO, KC_A, KC_O);
TP_COMBO_DEF(TP_TE, KC_T, KC_E);

TP_COMBO_DEF(TP_OT, KC_O, KC_T);
TP_COMBO_DEF(TP_SN, KC_S, KC_N);
TP_COMBO_DEF(TP_AE, KC_A, KC_E);
TP_COMBO_DEF(TP_RI, KC_R, KC_I);
TP_COMBO_DEF(TP_RN, KC_R, KC_N);
TP_COMBO_DEF(TP_SI, KC_S, KC_I);
TP_COMBO_DEF(TP_AT, KC_A, KC_T);
TP_COMBO_DEF(TP_OE, KC_O, KC_E);
TP_COMBO_DEF(TP_RT, KC_R, KC_T);
TP_COMBO_DEF(TP_OI, KC_O, KC_I);
TP_COMBO_DEF(TP_SE, KC_S, KC_E);
TP_COMBO_DEF(TP_AN, KC_A, KC_N);
TP_COMBO_DEF(TP_RE, KC_R, KC_E);
TP_COMBO_DEF(TP_AI, KC_A, KC_I);
TP_COMBO_DEF(TP_ST, KC_S, KC_T);
TP_COMBO_DEF(TP_ON, KC_O, KC_N);
TP_COMBO_DEF(TP_RO, KC_R, KC_O);
TP_COMBO_DEF(TP_TI, KC_T, KC_I);
TP_COMBO_DEF(TP_NE, KC_N, KC_E);
TP_COMBO_DEF(TP_AS, KC_A, KC_S);


TP_COMBO_DEF(TP_RA, KC_R, KC_A);
TP_COMBO_DEF(TP_SO, KC_S, KC_O);
TP_COMBO_DEF(TP_NT, KC_N, KC_T);
TP_COMBO_DEF(TP_IE, KC_I, KC_E);
TP_COMBO_DEF3(TP_SNI, KC_S, KC_N, KC_I);
TP_COMBO_DEF3(TP_OTE, KC_O, KC_T, KC_E);

combo_t key_combos[] = {
    TP_COMBO_ACTION(TP_RS),
    TP_COMBO_ACTION(TP_NI),
    TP_COMBO_ACTION(TP_AO),
    TP_COMBO_ACTION(TP_TE),
    TP_COMBO_ACTION(TP_OT),
    TP_COMBO_ACTION(TP_SN),
    TP_COMBO_ACTION(TP_AE),
    TP_COMBO_ACTION(TP_RI),
    TP_COMBO_ACTION(TP_RN),
    TP_COMBO_ACTION(TP_SI),
    TP_COMBO_ACTION(TP_AT),
    TP_COMBO_ACTION(TP_OE),
    TP_COMBO_ACTION(TP_RT),
    TP_COMBO_ACTION(TP_OI),
    TP_COMBO_ACTION(TP_SE),
    TP_COMBO_ACTION(TP_AN),
    TP_COMBO_ACTION(TP_RE),
    TP_COMBO_ACTION(TP_AI),
    TP_COMBO_ACTION(TP_ST),
    TP_COMBO_ACTION(TP_ON),
    TP_COMBO_ACTION(TP_RO),
    TP_COMBO_ACTION(TP_TI),
    TP_COMBO_ACTION(TP_NE),
    TP_COMBO_ACTION(TP_AS),
    TP_COMBO_ACTION(TP_RA),
    TP_COMBO_ACTION(TP_SO),
    TP_COMBO_ACTION(TP_NT),
    TP_COMBO_ACTION(TP_IE),
    TP_COMBO_ACTION(TP_SNI),
    TP_COMBO_ACTION(TP_OTE),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        TP_COMBO_MOD_HANDLE_CHAR(    TP_RS, KC_B, KC_9)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_NI, KC_Y, KC_5)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_AO, KC_L, KC_4)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_TE, KC_H, KC_0)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_OT, KC_U, KC_7)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_SN, KC_P, KC_2)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_AE, KC_D, KC_HASH)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_RI, KC_G, KC_AT)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_RN, KC_Z, KC_8)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_SI, KC_F, KC_6)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_AT, KC_Q, KC_3)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_OE, KC_C, KC_1)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_RT, KC_X, KC_CIRC)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_OI, KC_K, KC_PLUS)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_SE, KC_V, KC_ASTR)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_AN, KC_J, KC_EQL)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_RE, KC_M, KC_DLR)
        TP_COMBO_MOD_HANDLE_CHAR(    TP_AI, KC_W, KC_AMPR)
        TP_COMBO_MOD_HANDLE(    TP_ST, KC_SLSH, KC_BSLS, KC_PIPE)
        TP_COMBO_MOD_HANDLE(    TP_ON, KC_MINS, KC_UNDS, KC_PERC)
        TP_COMBO_MOD_HANDLE(    TP_RO, KC_SCLN, KC_COLN, KC_SPC)
        TP_COMBO_MOD_HANDLE(    TP_TI, KC_QUES, KC_EXLM, KC_SPC)
        TP_COMBO_MOD_HANDLE(    TP_NE, KC_COMM, KC_DOT,  KC_TILD)
        TP_COMBO_MOD_HANDLE(    TP_AS, KC_QUOT, KC_DQT,  KC_GRV)
        TP_COMBO_MOD_HANDLE_OSM(TP_RA, KC_LGUI, KC_RIGHT, KC_PGUP)
        TP_COMBO_MOD_HANDLE_OSM(TP_SO, KC_LALT, KC_UP,    KC_HOME)
        TP_COMBO_MOD_HANDLE_OSM(TP_NT, KC_LCTL, KC_DOWN,  KC_END)
        TP_COMBO_MOD_HANDLE_OSM(TP_IE, KC_LSFT, KC_LEFT,  KC_PGDN)
        TP_COMBO_MOD_HANDLE(    TP_SNI, KC_TAB, KC_DEL, KC_BSPC)
        TP_COMBO_MOD_HANDLE(    TP_OTE, KC_ENT, KC_ESC, KC_F2)
    }
}
// todos: TP_SNI / TP_OTE: handle FN correct and find out what AGR means...
