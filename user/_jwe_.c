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
#include "transactions.h"
#include "split_util.h"

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CAPS_WORD_ENABLE
    if(keycode == OSM(MOD_LSFT) && is_caps_word_on()) {
        caps_word_off();
        return false;
    }
#endif
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

void user_sync_rgb_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
#ifdef RGB_MATRIX_DEFAULT_MODE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
    /* transaction_register_rpc(SYNC_RGB_STATE, user_sync_rgb_slave_handler); */
    theme_init();
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


bool is_keyboard_idle = false;
static uint32_t key_timer;
/**/
void housekeeping_task_user(void) {
#ifdef KEYBOARD_IDLE_TIME
    check_idle_timeout();
#endif
}
void refresh_idle(void) {
    key_timer = sync_timer_read32(); // store time of last refresh
    if (is_keyboard_idle)
    {
        is_keyboard_idle = false;
#ifdef RGB_MATRIX_ENABLE
        rgb_matrix_enable_noeeprom();
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#endif // RGB_MATRIX_ENABLE
    }
}

bool check_idle_timeout(void) {
    if (sync_timer_elapsed32(key_timer) > KEYBOARD_SLEEP_TIME)
    {
#ifdef RGB_MATRIX_ENABLE
        rgb_matrix_disable_noeeprom();
#endif // RGB_MATRIX_ENABLE
        return (true);
    }
    else if (!is_keyboard_idle && sync_timer_elapsed32(key_timer) > KEYBOARD_IDLE_TIME)
    {
        is_keyboard_idle = true;
#ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
#endif // RGB_MATRIX_ENABLE
#ifdef OLED_ENABLE
        oled_off();
#endif
        return(true);
    }
    return (false);
}
#ifdef KEYBOARD_IDLE_TIME
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
        oled_on();
#endif
    if (record->event.pressed)
        refresh_idle();
}

/* void user_sync_rgb_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) { */
/*     is_keyboard_idle = *(bool*)in_data; */
/*     if (is_keyboard_idle) */
/*     { */
/* #ifdef RGB_MATRIX_ENABLE */
/*         rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE); */
/* #endif // RGB_MATRIX_ENABLE */
/*     } else { */
/* #ifdef RGB_MATRIX_ENABLE */
/*         rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE); */
/* #endif // RGB_MATRIX_ENABLE */
/*     } */
/* } */


#endif // ifdef KEYBOARD_IDLE_TIME


//----------------------------------------------------------
// Sync

theme_runtime_config theme_state;

void rpc_theme_sync_callback(uint8_t m2s_size, const void *m2s_buffer, uint8_t s2m_size, void *s2m_buffer) {
    if (m2s_size == sizeof(theme_state)) {
        memcpy(&theme_state, m2s_buffer, m2s_size);
    }
}

void theme_init(void) {
    // Register keyboard state sync split transaction
    transaction_register_rpc(THEME_DATA_SYNC, rpc_theme_sync_callback);

    // Reset the initial shared data value between master and slave
    memset(&theme_state, 0, sizeof(theme_state));
}

void theme_state_update(void) {
    if (is_keyboard_master()) {
        // Keep the scan rate in sync
        theme_state.scan_rate = is_keyboard_idle;
    }
}

void theme_state_sync(void) {
    if (!is_transport_connected()) return;

    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static theme_runtime_config last_theme_state;
        static uint32_t             last_sync;
        bool                        needs_sync = false;

        // Check if the state values are different
        if (memcmp(&theme_state, &last_theme_state, sizeof(theme_runtime_config))) {
            needs_sync = true;
            memcpy(&last_theme_state, &theme_state, sizeof(theme_runtime_config));
        }

        // Send to slave every 125ms regardless of state change
        if (timer_elapsed32(last_sync) > 125) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(THEME_DATA_SYNC, sizeof(theme_runtime_config), &theme_state)) {
                last_sync = timer_read32();
            } else {
                dprint("Failed to perform rpc call\n");
            }
        }
    }
}
