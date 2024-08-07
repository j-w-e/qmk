// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "_jwe_.h"

#define _LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_jwe_wrapper(...) _LAYOUT_wrapper(LAYOUT_ADD_THUMBS(LAYOUT_5x3_TO_6x3(__VA_ARGS__)))

#define _LAYOUT_themb_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_themb_jwe_wrapper(...) _LAYOUT_themb_wrapper(LAYOUT_ADD_THeMBS(LAYOUT_5x3_TO_6x3(__VA_ARGS__)))

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APTMAK] = LAYOUT_themb_jwe_wrapper(_ALPHAS_APTMAK),
    [SYM] = LAYOUT_jwe_wrapper(_ALPHAS_SYMBOLS),
    [NAV] = LAYOUT_jwe_wrapper(_ALPHAS_NAV),
    [NUM] = LAYOUT_jwe_wrapper(_ALPHAS_NUMBERS),
    [MOUSE] = LAYOUT_jwe_wrapper(_ALPHAS_MOUSE),
    [SYM2] = LAYOUT_jwe_wrapper(_ALPHAS_SYM2),
    [FUNC] = LAYOUT_jwe_wrapper(_ALPHAS_FUNC),
};
