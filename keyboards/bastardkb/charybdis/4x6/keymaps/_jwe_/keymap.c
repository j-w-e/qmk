/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "_jwe_.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/*enum charybdis_keymap_layers {*/
/*    LAYER_BASE = 0,*/
/*    LAYER_LOWER,*/
/*    LAYER_RAISE,*/
/*    LAYER_POINTER,*/
/*};*/

/** \brief Automatically enable sniping-mode on the pointer layer. */
/*#define CHARYBDIS_AUTO_SNIPING_ON_LAYER POINT*/

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

/*#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS*/
/*#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 500*/
/*#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS*/
#    undef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 750

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/*#define LOWER MO(LAYER_LOWER)*/
/*#define RAISE MO(LAYER_RAISE)*/
/*#define PT_Z LT(LAYER_POINTER, KC_Z)*/
/*#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)*/

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE


#define _LAYOUT_wrapper(...) LAYOUT_charybdis_4x6(__VA_ARGS__)
#define LAYOUT_jwe_wrapper(...) _LAYOUT_wrapper(LAYOUT_charybdis_wrapper(LAYOUT_ADD_THUMBS(LAYOUT_5x3_TO_6x3(__VA_ARGS__))))

#define _LAYOUT_themb_wrapper(...) LAYOUT_charybdis_4x6(__VA_ARGS__)
#define LAYOUT_themb_jwe_wrapper(...) _LAYOUT_themb_wrapper(LAYOUT_charybdis_wrapper(LAYOUT_ADD_THeMBS(LAYOUT_5x3_TO_6x3(__VA_ARGS__))))

#define LAYOUT_wrapper(...) LAYOUT_charybdis_4x6(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [APTMAK] = LAYOUT_themb_jwe_wrapper(_ALPHAS_APTMAK),
    [SYM] = LAYOUT_jwe_wrapper(_ALPHAS_SYMBOLS),
    [NAV] = LAYOUT_jwe_wrapper(_ALPHAS_NAV),
    [NUM] = LAYOUT_jwe_wrapper(_ALPHAS_NUMBERS),
    [MOUSE] = LAYOUT_jwe_wrapper(_ALPHAS_MOUSE),
    [SYM2] = LAYOUT_jwe_wrapper(_ALPHAS_SYM2),
    [FUNC] = LAYOUT_jwe_wrapper(_ALPHAS_FUNC),
    [POINT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, KC_BTN1, _______,    _______, KC_BTN1,
                                        TO(APTMAK), KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(POINT);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_kb(void) {
#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(POINT);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE
}

/*void matrix_scan_user(void) {*/
/*    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {*/
/*        auto_pointer_layer_timer = 0;*/
/*        layer_off(LAYER_POINTER);*/
/*#        ifdef RGB_MATRIX_ENABLE*/
/*        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);*/
/*#        endif // RGB_MATRIX_ENABLE*/
/*    }*/
/*}*/
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/*#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER*/
/*layer_state_t layer_state_set_user(layer_state_t state) {*/
/*    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));*/
/*    return state;*/
/*}*/
/*#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER*/
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
