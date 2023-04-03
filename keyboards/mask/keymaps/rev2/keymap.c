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

enum mask_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_QWERTY = SAFE_RANGE, KC_COLEMAK, KC_GAME, KC_LOWER, KC_RAISE, KC_ADJUST, KC_GHOME, KC_GEND, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE };

// MOD TAP helper
#define MT_A LCTL_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LSFT_T(KC_F)
#define MT_J RSFT_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_SCLN RCTL_T(KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                               |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | LSFT |   A  |   S  |   D  |   F  |   G  |                               |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+-------------.   .-------------+------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  | MUTE |  U   |   |   I  |   P  |   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `---------------------------+------+------+------+------|   |------+------+------+------+---------------------------'
 *                             | LALT | LGUI |LOWER |RAISE |   |ENTER |SPACE | RGUI | RALT |
 *                             `---------------------------'   '---------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
  KC_LSFT,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,     // no homerow mods
  KC_LCTL,  KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_U,        KC_I,    KC_P,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                                       KC_LALT, KC_LGUI, KC_LOWER, KC_RAISE,    KC_ENT,  KC_SPC, KC_RGUI, KC_RALT
),

/*
 * COLEMAK
 * ,-----------------------------------------.                                 ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                                 |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                                 |   J  |   L  |   U  |   Y  |   ;  | DEL  |
 * |------+------+------+------+------+------|                                 |------+------+------+------+------+------|
 * | LSFT |   A  |   R  |   S  |   T  |   D  |                                 |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|-------------.    .--------------|------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  | MUTE | U    |    |       |      |   K  |   M  |   ,  |   .  |   /  | RSFT |
 * `---------------------------+-------------+------+------+    |-------+------+------+------+---------------------------'
 *                             | LALT | LGUI |LOWER |RAISE |    | ENTER |SPACE | RGUI | RALT |
 *                             '---------------------------'    '----------------------------'
 */
[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_F,    KC_P,    KC_G,                                             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_LSFT,  KC_A,   KC_R,     KC_S,    KC_T,    KC_D,                                             KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    KC_MUTE,  KC_U,        XXXXXXX, XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                       KC_LALT, KC_LGUI, KC_LOWER, KC_RAISE,    KC_ENT,  KC_SPC,  KC_RGUI, KC_RALT
),
/*
 * GAME
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                               |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | LSFT |   A  |   S  |   D  |   F  |   G  |                               |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+-------------.   .-------------+------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  | MUTE |      |   |      |   ^  |   N  |   M  |   ,  |   .  |   /  | RSFT |
 * `---------------------------+------+------+------+------|   |------+------+------+------+---------------------------'
 *                             |  M   | LALT |SPACE |ENTER |   |RAISE |LOWER | RGUI | RALT |
 *                             `---------------------------'   '---------------------------'
 */
[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                                            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                            KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_DEL,
  KC_LSFT,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                                            KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    KC_MUTE, XXXXXXX,   XXXXXXX,  KC_CIRC,  KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                                       KC_M,    KC_LALT, KC_SPC,  KC_ENT,    KC_RAISE, KC_LOWER, KC_RGUI, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  | BSPC | // numbers moded with CTRL and GUI
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                               |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                               |   ^  |   &  |   *  |   (  |   )  |  _   |
 * |------+------+------+------+------+------+-------------.   .-------------+------+------+------+------+------+------|
 * | LSFT |  =   |  -   |  +   |   {  |   }  |      |      |   |      |      |   [  |   ]  |   |  |   :  |   \  | RSFT |
 * `-----------------------------------------+------+------|   |------+------+-----------------------------------------'
 *                             |      |      |      |ADJUST|   |      |      |      |      |
 *                             '---------------------------'   '----------------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX,   LCG(KC_1), LCG(KC_2), LCG(KC_3), LCG(KC_4), LCG(KC_5),                                          LCG(KC_6), LCG(KC_7), LCG(KC_8), LCG(KC_9), LCG(KC_0), KC_BSPC,
  KC_TILD,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                               KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,
  LSFT_GRV,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                                            KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_UNDS,
  _______,   KC_EQL,    KC_MINS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   _______, _______,      _______, _______, KC_LBRC,   KC_RBRC,   KC_PIPE,   KC_COLN,   KC_BSLS,   _______,
                                              _______,   _______,   _______, KC_ADJUST,    _______, _______, _______,   _______
),


/* RAISE
 * ,----------------------------------------.                                .----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                               | F6   |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * | CAPS |      |  UP  |      | VOLU |      |                               | PGUP | PGDN | DEL  | INS  |      | F12  |
 * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 * |      | LEFT | DOWN | RIGHT| VOLD |      |                               | LEFT | DOWN | UP   | RIGHT| HOME | END  |
 * |------+------+------+------+------+------+-------------.   .-------------|------+------+------+------+------+------|
 * |      |      |      |      | MUTE |      |      |      |   |      |      |      |      |      |      |      |      |
 * `-----------------------------------------+------+------|   |------+------+-----------------------------------------'
 *                             |      |      |ADJUST|      |   |      |      |      |      |
 *                             '---------------------------'   '----------------------------'
*/
[_RAISE] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_CAPS, XXXXXXX, KC_UP,   XXXXXXX, KC_VOLU, XXXXXXX,                                           KC_PGUP, KC_PGDN, KC_DEL,  KC_INS,  XXXXXXX, KC_F12,
  _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_VOLD, XXXXXXX,                                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, _______,   _______,     _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      _______, _______, KC_ADJUST, _______,     _______, _______, _______, _______
),


/* ADJUST
 *         | RGB COMMANDS             |
 * ,----------------------------------------.                                .------------------------------------------.
 * | BOOT |      |      |      |      |      |                               |LG+HOME|LG+END|      |      |      |      |
 * |------+------+------+------+------+------|                               |------ +------+------+------+------+------|
 * |      |TOGGLE| HUI  | VAI  | SAI  |      |                               |QWERTY | COLEM| GAME |      |      |      |
 * |------+------+------+------+------+------|                               |------ +------+------+------+------+------|
 * |      | MOD  | HUD  | VAD  | SAD  |      |                               |       |      |      |      |      |      |
 * |------+------+------+------+------+------+-------------.   .-------------|-------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   |      |      |       |      |      |      |      |      |
 * `---------------------------+------+------+------+------|   |------+------+-------+------+---------------------------'
 *                             |      |      |      |      |   |      |      |       |      |
 *                             '---------------------------'   '----------------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         KC_GHOME,  KC_GEND,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_TOG, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX,                                         KC_QWERTY, KC_COLEMAK, KC_GAME, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_MOD, RGB_HUD, RGB_VAD, RGB_SAD, XXXXXXX,                                         XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      _______, _______, _______, _______,     _______, _______, _______,   _______
  )
};
// clang-format off
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
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
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
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
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

//void keyboard_post_init_user(void)
//{
//    debug_enable = true;
//    debug_matrix = false;
//    debug_keyboard = true;
//    debug_mouse = false;
//}

