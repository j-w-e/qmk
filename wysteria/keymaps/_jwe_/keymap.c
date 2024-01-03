// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "_jwe_.h"

/* #define _LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__) */
/* #define LAYOUT_jwe_wrapper(...) _LAYOUT_wrapper(LAYOUT_ADD_THUMBS(LAYOUT_5x3_TO_6x3(__VA_ARGS__))) */
/**/
/* #define _LAYOUT_themb_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__) */
/* #define LAYOUT_themb_jwe_wrapper(...) _LAYOUT_themb_wrapper(LAYOUT_ADD_THeMBS(LAYOUT_5x3_TO_WYST(__VA_ARGS__))) */
/**/
/* #define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_wyst_custom(
        QK_RBT, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        /* RGB_TOG, RGB_MOD, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, RGB_MOD, RGB_TOG, */
        KC_LCTL, KC_LSFT, KC_SPC, KC_MUTE, KC_MUTE, KC_ENT, KC_LGUI, KC_LALT
    )
    /* [APTMAK] = LAYOUT_themb_jwe_wrapper(_ALPHAS_APTMAK), */
    /* [SYM] = LAYOUT_jwe_wrapper(_ALPHAS_SYMBOLS), */
    /* [NAV] = LAYOUT_jwe_wrapper(_ALPHAS_NAV), */
    /* [NUM] = LAYOUT_jwe_wrapper(_ALPHAS_NUMBERS), */
    /* [MOUSE] = LAYOUT_jwe_wrapper(_ALPHAS_MOUSE), */
    /* [SYM2] = LAYOUT_jwe_wrapper(_ALPHAS_SYM2), */
    /* [FUNC] = LAYOUT_jwe_wrapper(_ALPHAS_FUNC), */
};
