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
/* #include "g/keymap_combo.h" */
#include "_jwe_.h"
#include "casemodes.h"

#ifndef NO_SECRETS
#include "secrets.h"
#endif

uint16_t sym_timer = ONESHOT_TIMEOUT + 1;

bool sw_win_active = false;
bool sw_apwin_active = false;

bool leader_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state jwe_shft_state = os_up_unqueued;
oneshot_state os_sym_state = os_up_unqueued;


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SYM:
        case LA_NAV:
        case LA_MOUSE:
        case LA_NUM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SYM:
        case LA_NAV:
        case LA_MOUSE:
        case LA_NUM:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NAV:
            if(layer_state_is(SYM)) {
                return false;
            }
        case OS_SYM:
        case LA_MOUSE:
        case LA_NUM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    switch (keycode) {
        /* case JWE_SHFT: */
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, SYM, NAV, SYM2);
    state = update_tri_layer_state(state, NUM, MOUSE, FUNC);

    return state;
};

#ifdef OLED_ENABLE

#ifndef BONGOCAT
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
#endif

void oled_render_layer_state_r2g_jwe(void) {
    oled_write_P(PSTR("lyr:"), false);
    oled_advance_page(true);
    switch (get_highest_layer(layer_state)) {
        case ENGRAM:
            oled_write_P(PSTR("EN"), false);
            break;
        case APTMAK:
            oled_write_P(PSTR("APMK"), false);
            break;

        case SYM:
            oled_write_P(PSTR("sm"), false);
            break;
        case NAV:
            oled_write_P(PSTR("nv"), false);
            break;
        case NUM:
            oled_write_P(PSTR("nm"), false);
            break;
        case SYM2:
            oled_write_P(PSTR("s2"), false);
            break;
        case MOUSE:
            oled_write_P(PSTR("m"), false);
            break;
        case FUNC:
            oled_write_P(PSTR("f"), false);
            break;
    }
    oled_advance_page(true);
#ifdef CAPS_WORD_ENABLE
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
#ifdef SWAP_HANDS_ENABLE
        oled_write_P(PSTR("CAPLK"), swap_hands);
#else
        oled_write_P(PSTR("CAPLK"), false);
#endif
    }
    else if (is_caps_word_on()) {
        oled_write_P(PSTR("CAP"), false);
        oled_advance_page(true);
    } else {
        oled_advance_page(true);
    }
#else
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
#ifdef SWAP_HANDS_ENABLE
        oled_write_P(PSTR("CAPLK"), swap_hands);
#else
        oled_write_P(PSTR("CAPLK"), false);
#endif
        oled_advance_page(true);
    } else {
        oled_advance_page(true);
    }
#endif
}

void render_bootmagic_status_r2g_jwe(void) {
    static const char PROGMEM logo[][2][3] = {
        {{0x8b, 0x8c, 0}, {0xab, 0xac, 0}},
        {{0x89, 0x8a, 0}, {0xa9, 0xaa, 0}},
    };
        oled_advance_char();
        oled_write_P(logo[1][0], false);
        oled_advance_page(true);
        oled_advance_char();
        oled_write_P(logo[1][1], false);
    oled_advance_page(true);
#ifdef WPM_ENABLE
    oled_advance_page(true);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    oled_advance_page(true);
#endif // WPM_ENABLE

    oled_advance_page(true);
}

void render_mod_status(uint8_t modifiers) {
    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xcd, 0};
    static const char PROGMEM off_off_2[] = {0xce, 0};
    static const char PROGMEM on_off_1[] = {0xcf, 0};
    static const char PROGMEM on_off_2[] = {0xd0, 0};
    static const char PROGMEM off_on_1[] = {0xd1, 0};
    static const char PROGMEM off_on_2[] = {0xd2, 0};
    static const char PROGMEM on_on_1[] = {0xd3, 0};
    static const char PROGMEM on_on_2[] = {0xd4, 0};

    static const char PROGMEM gui_off_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_off_2[] = {0xad, 0xae, 0};
    static const char PROGMEM gui_on_1[] = {0x95, 0x96, 0};
    static const char PROGMEM gui_on_2[] = {0xb5, 0xb6, 0};

    static const char PROGMEM alt_off_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_off_2[] = {0xaf, 0xb0, 0};
    static const char PROGMEM alt_on_1[] = {0x97, 0x98, 0};
    static const char PROGMEM alt_on_2[] = {0xb7, 0xb8, 0};

    static const char PROGMEM ctrl_off_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_off_2[] = {0xb1, 0xb2, 0};
    static const char PROGMEM ctrl_on_1[] = {0x99, 0x9a, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb9, 0xba, 0};

    static const char PROGMEM shift_off_1[] = {0x93, 0x94, 0};
    static const char PROGMEM shift_off_2[] = {0xb3, 0xb4, 0};
    static const char PROGMEM shift_on_1[] = {0x9b, 0x9c, 0};
    static const char PROGMEM shift_on_2[] = {0xbb, 0xbc, 0};


    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }



    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }


    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }


    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }

}

void oled_render_logo_r2g_jwe(void) {
    static const char PROGMEM qmk_logo[] = {
        0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x80, 0x81, 0x82, 0x83,
        0x20, 0xA0, 0xA1, 0xA2, 0xA3,
        0x20, 0xC0, 0xC1, 0xC2, 0xC3,
        0x20, 0x20, 0x20, 0x20, 0x20,
        0x84, 0x85, 0x86, 0x87, 0x88,
        0xA4, 0xA5, 0xA6, 0xA7, 0xA8,
        0xC4, 0xC5, 0xC6, 0xC7, 0xC8,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x00
    };
    oled_write_P(qmk_logo, false);
}


bool oled_task_user(void) {

    if (is_keyboard_master()) {
        oled_render_layer_state_r2g_jwe();
        oled_advance_page(true);
        oled_advance_page(true);
        render_bootmagic_status_r2g_jwe();
        render_mod_status(get_mods() | get_oneshot_mods());
#ifdef LEADER_ENABLE
        if (leader_active) {
            oled_advance_page(true);
            oled_write_P(PSTR("LEAD"), false);
        } else {
            oled_advance_page(true);
            oled_advance_page(true);
        }
#endif // LEADER_ENABLE
    } else {
        oled_render_logo_r2g_jwe();
    }
    return false;
}
#endif // OLED_ENABLE

bool override_shift( bool is_shifted,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record) {
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
    }
    else {
        unregister_code16(shift_override);
        unregister_code16(keycode);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CAPS_WORD_ENABLE
    if(keycode == OS_SHFT && is_caps_word_on()) {
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
        case JWE_MNE:
            if (record->event.pressed) {
                SEND_STRING("M&E");
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

void keyboard_post_init_user(void) {
    layer_move(ENGRAM);
}

void leader_start_user(void) {
    leader_active = true;
}

void leader_end_user(void) {
    leader_active = false;

    if (leader_sequence_one_key(KC_H)) {
        SEND_STRING("Hugh");
    } else if (leader_sequence_two_keys(KC_L, KC_E)) {
        layer_move(ENGRAM);
    } else if (leader_sequence_two_keys(KC_L, KC_A)) {
        layer_move(APTMAK);
    } else if (leader_sequence_two_keys(KC_L, KC_N)) {
        layer_move(NAV);
    } else if (leader_sequence_two_keys(KC_G, KC_G)) {
        layer_on(MOUSE);
        layer_on(NUM);
#ifndef NO_SECRETS
        // secrets file contains:
        // 0 is segregation
        // 1 is email
        // 2 is phone number
        // 3 is OH's email
        // 4 is OH's phone number
        // 5 is work email
    } else if (leader_sequence_two_keys(KC_S, KC_E)) {
        send_secret(0);
    } else if (leader_sequence_two_keys(KC_S, KC_G)) {
        send_secret(1);
    } else if (leader_sequence_two_keys(KC_S, KC_P)) {
        send_secret(2);
    } else if (leader_sequence_two_keys(KC_S, KC_J)) {
        send_secret(3);
    } else if (leader_sequence_two_keys(KC_S, KC_K)) {
        send_secret(4);
    } else if (leader_sequence_two_keys(KC_S, KC_N)) {
        send_secret(5);
#endif
    /* } else if (leader_sequence_one_key(KC_X)) { */
    /*     enable_xcase_with(KC_UNDS); */
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        SEND_STRING(SS_LSFT(SS_LCMD("5")));
    } else if (leader_sequence_two_keys(KC_W, KC_B)) {
        SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL(SS_LALT("b")))));
    } else if (leader_sequence_two_keys(KC_W, KC_R)) {
        SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL(SS_LALT("r")))));
    } 

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
