// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "_jwe_.h"


#define LAYOUT_WYST(...) _LAYOUT_WYST(__VA_ARGS__)
#define _LAYOUT_wyst_custom(...) LAYOUT_wyst_custom(__VA_ARGS__)
#define _LAYOUT_WYST(...) _LAYOUT_wyst_custom(LAYOUT_ADD_WYST_THeMBS(__VA_ARGS__))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*     [0] = LAYOUT_wyst_custom( */
/*         KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, */
/*         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, */
/*         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_M, KC_N, KC_COMM, KC_DOT, KC_SLSH, */
/*         KC_LCTL, KC_LSFT, KC_SPC, KC_MUTE, KC_MUTE, KC_ENT, KC_LGUI, KC_LALT */
/* )  */
    [APTMAK] = LAYOUT_WYST(_ALPHAS_APTMAK),
    [SYM] = LAYOUT_WYST(_ALPHAS_SYMBOLS),
    [NAV] = LAYOUT_WYST(_ALPHAS_NAV),
    [NUM] = LAYOUT_WYST(_ALPHAS_NUMBERS),
    [MOUSE] = LAYOUT_WYST(_ALPHAS_MOUSE),
    [SYM2] = LAYOUT_WYST(_ALPHAS_SYM2),
    [FUNC] = LAYOUT_WYST(_ALPHAS_FUNC),
};
