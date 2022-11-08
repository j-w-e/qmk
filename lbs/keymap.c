// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* #define TEAMS_MUTE HYPR(KC_M) */
/* #define TEAMS_VIDEO HYPR(KC_V) */
#define TEAMS_MUTE G(S(KC_M))
#define TEAMS_VIDEO G(S(KC_K))  // THIS IN NOT Video, it's raise hand

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FUNC,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
            KC_MUTE,
            MO(_FUNC),  MO(_RGB),
            TEAMS_MUTE,TEAMS_VIDEO
            ),
    [_FUNC] = LAYOUT(
            KC_MUTE,
            KC_NO,      QK_MAKE,
            KC_A,      QK_BOOT
            ),
    [_RGB] = LAYOUT(
            KC_MUTE,
            RGB_VAI,    KC_NO,
            RGB_VAD,    RGB_TOG
            )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
};
