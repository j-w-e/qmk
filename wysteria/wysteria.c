/**
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
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
#include "quantum.h"

/**
 * LEDs index.
 *
 * ╭────────────────────╮                 ╭────────────────────╮
 *   17  12  11   6   5                     23  24  29  30  35
 * ├────────────────────┤                 ├────────────────────┤
 *   16  13  10   7   4                     22  25  28  31  34
 * ├────────────────────┤                 ├────────────────────┤
 *   15  14   9   8   3                     21  26  27  32  33
 * ╰────────────────────╯                 ╰────────────────────╯
 *                    0   1   2     18  19  20
 *                 ╰────────────╯ ╰────────────╯
 */

// clang-format off
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    /* Key Matrix to LED index. */
    // Left split - final column is thumb cluster
    // columns are: pinky, ring, middle, index, inner, thumb, in that order
    // for thumb col, top row is reachy thumb, bottom row is tucky thumb
    {      17,      12,      11,      6,     5,    0    }, // Top row
    {      16,      13,      10,      7,     4,    1    }, // Middle row
    {      15,      14,      9,       8,     3,    2    }, // Bottom row
    {     NO_LED, NO_LED,     NO_LED,     NO_LED, NO_LED, NO_LED }, // I actually don't understand why this is necessary, but it works
    // Right split - final column is thumb cluster
    // columns are: pinky, ring, middle, index, inner, thumb, in that order
    // for thumb col, top row is reachy thumb, bottom row is tucky thumb
    {     35,       30,     29,     24,    23,   18    }, // Top row
    {     34,       31,     28,     25,    22,   19    }, // Middle row
    {     33,       32,     27,     26,    21,   20    }, // Bottom row
    {     NO_LED, NO_LED,     NO_LED,     NO_LED, NO_LED, NO_LED }, // I actually don't understand why this is necessary, but it works
}, {
    /* LED index to physical position. */
    // Left split.
    /* index=0  */ {   0,  42 }, {   0,  21 }, {   0,   0 }, // col 1 (left most)
    /* index=3  */ {  18,   0 }, {  18,  21 }, {  18,  42 }, // col 2
    /* index=6  */ {  36,  42 }, {  36,  21 }, {  36,   0 },
    /* index=9  */ {  54,   0 }, {  54,  21 }, {  54,  42 },
    /* index=12 */ {  72,   0 }, {  72,  21 }, {  72,  42 },
    /* index=15 */ {  72,  64 }, {  90,  64 }, { 108,  64 }, // Thumb cluster
    // Right split.
    /* index=18 */ { 224,  42 }, { 224,  21 }, { 224,   0 }, // col 10 (right most)
    /* index=21 */ { 206,   0 }, { 206,  21 }, { 206,  42 }, // col 9
    /* index=24 */ { 188,  42 }, { 188,  21 }, { 188,   0 },
    /* index=27 */ { 170,   0 }, { 170,  21 }, { 170,  42 },
    /* index=30 */ { 152,   0 }, { 152,  21 }, { 152,  42 },
    /* index=33 */ { 152,  64 }, { 134,  64 }, { 116,  64 }, // Thumb cluster
}, {
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 1
    /* index=3  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 2
    /* index=6  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=9  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=12 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=15 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // Thumb cluster
    // Right split.
    /* index=18 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 10
    /* index=21 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 9
    /* index=24 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=27 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=30 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=33 */ LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, // Thumb cluster
} };
#endif
// clang-format on
