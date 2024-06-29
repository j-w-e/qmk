/* Copyright 2021 @j-w-e
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

uint16_t sym_timer = ONESHOT_TIMEOUT + 1;
bool sw_win_active = false;
bool sw_apwin_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_sym_state = os_up_unqueued;

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, SYM, NAV, SYM2);
    state = update_tri_layer_state(state, NUM, MOUSE, FUNC);

    return state;
};

bool override_shift(bool is_shifted, uint16_t shift_override, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_shifted) {
            uint8_t mod_state = get_mods();
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);

            register_code16(shift_override);

            set_mods(mod_state);
        } else {
            // regular: /
            register_code16(keycode);
        }
        return false;
    } else {
        unregister_code16(shift_override);
        unregister_code16(keycode);
    }

    return true;
}

void matrix_scan_user (void) {
    if (os_sym_state == os_up_queued) {
        if ( timer_elapsed(sym_timer) > ONESHOT_TIMEOUT ) {
            layer_off(SYM);
            sym_timer = ONESHOT_TIMEOUT + 1;
            os_sym_state = os_up_unqueued;
        }
    }
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: return KC_K;  // In place of alt-fingering ck
        case KC_H: return KC_T;  // To ease the ght trigram
    //  case KC_Y: return 'OU' to allow typing you easily
    }

    return keycode;  // Defer to default definitions.
}

static fast_timer_t tap_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CAPS_WORD_ENABLE
    if(keycode == OSM(MOD_LSFT) && is_caps_word_on()) {
        caps_word_off();
        return false;
    }
#endif
    if (record->event.pressed) {
        tap_timer = timer_read_fast();
    }
    update_swapper(
            &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
            keycode, record
            );
    update_swapper(
            &sw_apwin_active, KC_LGUI, BCKTICK, SW_AWIN,
            keycode, record
            );

    update_oneshot(
            &os_shft_state, KC_LSFT, OS_SHFT,
            keycode, record
            );
    update_oneshot(
            &os_ctrl_state, KC_LCTL, OS_CTRL,
            keycode, record
            );
    update_oneshot(
            &os_cmd_state, KC_LCMD, OS_CMD,
            keycode, record
            );
    update_oneshot(
            &os_alt_state, KC_LALT, OS_ALT,
            keycode, record
            );
    bool handled = true;
    handled = update_oneshot_layer(
            &os_sym_state, SYM, OS_SYM,
            keycode, record, &sym_timer
            ) & handled;

    bool is_shifted =
        (get_mods() & MOD_MASK_SHIFT) ||
        (get_oneshot_mods() & MOD_MASK_SHIFT);

    switch(keycode) {
        case KC_COMMA:
            return override_shift(is_shifted, KC_SCLN, keycode, record);
        case KC_DOT:
            return override_shift(is_shifted, KC_COLN, keycode, record);
        case KC_BSPC:
            return override_shift(is_shifted, KC_DEL, keycode, record);
        case KC_SLASH:
            return override_shift(is_shifted, KC_SLASH, keycode, record);
        case JWE_MNE:
            if (record->event.pressed) {
                SEND_STRING("MEL");
            }
            return false;
        case JWE_NRC:
            if (record->event.pressed) {
                SEND_STRING("NRC");
            }
            return false;
        case JWE_PROJ:
            if (record->event.pressed) {
                SEND_STRING("NOUA0007");
            }
            return false;
        case LA_NAV:
            if (record->event.pressed) {
                if(os_sym_state == os_up_queued_used) {
                    layer_off(SYM);
                    os_sym_state = os_up_unqueued;
                    sym_timer = ONESHOT_TIMEOUT + 1;
                }
                layer_on(NAV);
            } else {
                layer_off(NAV);
            }
            return false;
        case LA_NUM:
            if (record->event.pressed) {
                layer_on(NUM);
            } else {
                layer_off(NUM);
            }
            return false;
        case LA_MOUSE:
            if (record->event.pressed) {
                layer_on(MOUSE);
            } else {
                layer_off(MOUSE);
            }
            return false;

        case SLEEP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LCMD("q")) SS_DELAY(500) SS_TAP(X_ESC));
            }
            return false;

    }
    return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Increase tapping term for the home row mod-tap while typing
    if (timer_elapsed_fast(tap_timer) < TAPPING_TERM * 3) {
        return TAPPING_TERM * 3;
    }
    return TAPPING_TERM;
}
#endif

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
#ifdef RGB_MATRIX_DEFAULT_MODE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#endif /* ifdef RGB_MATRIX_DEFAULT_MODE */
#endif /* ifdef RGB_MATRIX_ENABLE */
#ifdef LIATRIS
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
#endif /* ifdef LIATRIS */
}


/* bool is_keyboard_idle = false; */
/* static uint32_t key_timer; */
/**/
/* void housekeeping_task_user(void) { */
/* #ifdef KEYBOARD_IDLE_TIME */
/*     check_idle_timeout(); */
/* #endif */
/* } */
/* void refresh_idle(void) { */
/*     key_timer = timer_read32(); // store time of last refresh */
/*     if (is_keyboard_idle) */
/*     { */
/*         is_keyboard_idle = false; */
/* #ifdef RGB_MATRIX_ENABLE */
/*         rgb_matrix_enable_noeeprom(); */
/*         rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE); */
/* #endif // RGB_MATRIX_ENABLE */
/*     } */
/* } */
/**/
/* bool check_if_oled_should_be_on(void) { */
/*     return !(is_keyboard_idle && timer_elapsed32(key_timer) > KEYBOARD_IDLE_TIME); */
/* } */
/**/
/* void check_idle_timeout(void) { */
/*     if (timer_elapsed32(key_timer) > KEYBOARD_SLEEP_TIME) */
/*     { */
/* #ifdef RGB_MATRIX_ENABLE */
/*         rgb_matrix_disable_noeeprom(); */
/* #endif // RGB_MATRIX_ENABLE */
/*     } */
/*     else if (!is_keyboard_idle && timer_elapsed32(key_timer) > KEYBOARD_IDLE_TIME) */
/*     { */
/*         is_keyboard_idle = true; */
/* #ifdef RGB_MATRIX_ENABLE */
/*         rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE); */
/* #endif // RGB_MATRIX_ENABLE */
/* #ifdef OLED_ENABLE */
/*         oled_off(); */
/* #endif */
/*     } */
/* } */
/* #ifdef KEYBOARD_IDLE_TIME */
/* void post_process_record_user(uint16_t keycode, keyrecord_t *record) { */
/* #ifdef OLED_ENABLE */
/*         oled_on(); */
/* #endif */
/*     if (record->event.pressed) */
/*         refresh_idle(); */
/* } */
/* #endif // ifdef KEYBOARD_IDLE_TIME */
