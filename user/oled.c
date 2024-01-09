#include QMK_KEYBOARD_H
#include "defines.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_render_layer_state_r2g_jwe(void) {
#ifdef SWAP_HANDS_ENABLE
    oled_write_P(PSTR("lyr:"), is_swap_hands_on());
#else
    oled_write_P(PSTR("lyr:"), false);
#endif
    oled_advance_page(true);
    switch (get_highest_layer(layer_state)) {
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
            oled_write_P(PSTR("wmm"), false);
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
        if (leader_sequence_active()) {
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
