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
#include "mask.h"

#ifdef RGB_MATRIX_ENABLE

// clang-format off
// Physicacl layout
//   10   25   40   55   70   85   100 (115) 130   145  160  175  190  205  220     // X LED POSITIONS
// -------------------------------                -------------------------------
// | 06   05   04   03   02   01 |                | 32   33   34   35   36   37 |
// |-----------------------------|                |-----------------------------|
// | 12   11   10   09   08   07 |                | 38   39   40   41   42   43 |
// |-----------------------------|                |-----------------------------|
// | 18   17   16   15   14   13 |                | 44   45   46   47   48   49 |   32 (y)
// |-----------------------------------      -----------------------------------|
// | 24   23   22   21   20   19   25 |      | 56   50   51   52   53   54   55 |
// -------------------------------------    -------------------------------------
//            | 30   29   28   27   26 |    | 57   58   59   60   61 |
//            --------------------------    --------------------------
//              45   60   75   90   105      125  140  155  170  185                // X LED POSITIONS
//
// Electrical layout
//    C  00   01   02   03   04   05   06   07   08   09   10   11
//     -------------------------------------------------------------
//  00 | 06   05   04   03   02   01 | 32   33   34   35   36   37 |
//     ------------------------------|------------------------------
//  01 | 12   11   10   09   08   07 | 38   39   40   41   42   43 |
//     ------------------------------|------------------------------
//  02 | 18   17   16   15   14   13 | 44   45   46   47   48   49 |
//     ------------------------------|------------------------------
//  03 | 24   23   22   21   20   19 | 50   51   52   53   54   55 |
//     ------------------------------|------------------------------
//  04 | 30   29   28   27   26   25 | 56   57   58   59   60   61 |
//     -------------------------------------------------------------

led_config_t g_led_config = {
    {
    // COL 00   01   02   03   04   05             ROW
        {   6,   5,   5,   3,   2,   1 },       // 00
        {  12,  11,  10,   9,   8,   7 },       // 01
        {  18,  17,  16,  15,  14,  13 },       // 02
        {  24,  23,  22,  21,  20,  19 },       // 03
        {  30,  29,  28,  27,  26,  25 },       // 04

    // COL 11   10   09   08   07   06             ROW
        {  37,  36,  35,  34,  33,  32 },       // 00
        {  43,  42,  41,  40,  39,  38 },       // 01
        {  49,  48,  47,  46,  45,  44 },       // 02
        {  55,  54,  53,  52,  51,  50 },       // 03
        {  61,  60,  59,  58,  57,  56 }        // 04
    },
    {
        // column spacing: 15
        // center: 115 / 32
        // top left: 0 / 0
        // bottom right: 230 / 64
       // Left side underglow / modifier
        {98, 33}, 
        // Left side Matrix
        {85,  4},  {70,  2},  {55,  0}, {40,  2}, {25,  9}, {10,  9},
        {85, 18},  {70, 16},  {55, 14}, {40, 16}, {25, 22}, {10, 22},
        {85, 31},  {70, 29},  {55, 28}, {40, 29}, {25, 36}, {10, 36},
        {85, 45},  {70, 43},  {55, 41}, {40, 43}, {25, 49}, {10, 49},
        {100, 46}, {105, 64}, {90, 60}, {75, 58}, {60, 57}, {45, 57},



        // Right side underglow / modifier
        {132, 33}, 
        // Right side Matrix
        {145,  4}, {160,  2}, {175,  0}, {190,  2}, {205,  9}, {220,  9},
        {145, 18}, {160, 16}, {175, 14}, {190, 16}, {205, 22}, {220, 22},
        {145, 31}, {160, 29}, {175, 28}, {190, 29}, {205, 36}, {220, 36},
        {145, 45}, {160, 43}, {175, 41}, {190, 43}, {205, 49}, {220, 49},
        {130, 46}, {125, 64}, {140, 60}, {155, 58}, {170, 57}, {185, 57}
    },
    {
        LED_FLAG_MODIFIER, 
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_MODIFIER, 
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
#endif

#ifdef SWAP_HANDS_ENABLE

__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] =
    // The LAYOUT macro could work for this, but it was harder to figure out the
    // identity using it.

    // This is the identity layout.
/*
{ \
    { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} }, \
    { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} }, \
    { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} }, \
    { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} }, \
    { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} }, \
    \
    { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} }, \
    { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} }, \
    { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} }, \
    { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} }, \
    { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} }, \
};
*/

    // This is the mirror, q <-> p, w <-> o, etc...
{ \
 { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} }, \
 { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} }, \
 { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} }, \
 { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} }, \
 { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} }, \
                                                     \
 { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} }, \
 { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} }, \
 { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} }, \
 { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} }, \
 { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} }, \
};

#endif

// clang-format on
