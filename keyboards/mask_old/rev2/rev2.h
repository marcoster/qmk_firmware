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
#pragma once
#include "quantum.h"
// clang-format off
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                     R02, R03, R04, R05, R06, R07,  \
    L10, L11, L12, L13, L14, L15,                     R12, R13, R14, R15, R16, R17,  \
    L20, L21, L22, L23, L24, L25,                     R22, R23, R24, R25, R26, R27,  \
    L30, L31, L32, L33, L34, L35, L36, L37, R30, R31, R32, R33, R34, R35, R36, R37,  \
                        L44, L45, L46, L47, R40, R41, R42, R43       \
    ) \
    { \
        { L00,   L01,   L02,   L03,   L04,   L05,   KC_NO, KC_NO }, \
        { L10,   L11,   L12,   L13,   L14,   L15,   KC_NO, KC_NO }, \
        { L20,   L21,   L22,   L23,   L24,   L25,   KC_NO, KC_NO }, \
        { L30,   L31,   L32,   L33,   L34,   L35,   L36,   L37 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, L44,   L45,   L46,   L47 }, \
        { R07,   R06,   R05,   R04,   R03,   R02,   KC_NO, KC_NO }, \
        { R17,   R16,   R15,   R14,   R13,   R12,   KC_NO, KC_NO }, \
        { R27,   R26,   R25,   R24,   R23,   R22,   KC_NO, KC_NO }, \
        { R37,   R36,   R35,   R34,   R33,   R32,   R31,   R30 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, R43,   R42,   R41,   R40 } \
    }
// clang-format on
