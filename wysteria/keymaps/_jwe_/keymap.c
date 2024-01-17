// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "_jwe_.h"


/* #define LAYOUT_WYST(...) _LAYOUT_WYST(__VA_ARGS__) */
#define _LAYOUT_wyst_custom(...) LAYOUT_wyst_custom(__VA_ARGS__)
/* #define _LAYOUT_WYST(...) _LAYOUT_wyst_custom(LAYOUT_ADD_WYST_THeMBS(__VA_ARGS__)) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // the first entry is the wrapper, as per the defines. 
    // the second and third are what I want the encoder presses to be (left, then right)
    // the wrappers automatically set this to the right place in the layout function
    [APTMAK] = LAYOUT_WYST(_ALPHAS_APTMAK, KC_MUTE, A(G(S(KC_M)))),
    [SYM] = LAYOUT_WYST(_ALPHAS_SYMBOLS, _______, _______),
    [NAV] = LAYOUT_WYST(_ALPHAS_NAV, _______, A(G(S(KC_C)))),
    [NUM] = LAYOUT_WYST(_ALPHAS_NUMBERS, _______, A(G(S(KC_B)))),
    [MOUSE] = LAYOUT_WYST(_ALPHAS_MOUSE, _______, _______),
    [SYM2] = LAYOUT_WYST(_ALPHAS_SYM2, _______, _______),
    [FUNC] = LAYOUT_WYST(_ALPHAS_FUNC, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [APTMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [SYM] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [NAV] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [NUM] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [MOUSE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [SYM2] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [FUNC] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
};
#endif
