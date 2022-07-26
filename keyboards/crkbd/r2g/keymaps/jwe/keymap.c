#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_uk.h"

#include "oneshot.h"
#include "swapper.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TABL G(S(KC_LBRC))
#define TABR G(S(KC_RBRC))
#define SPACE_L C(KC_LEFT)
#define SPACE_R C(KC_RGHT)
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define LA_NUM MO(NUM)
#define LA_MOUSE MO(MOUSE)

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_MAC_REDO LGUI(KC_Y)

#define SLEEP S(C(KC_POWER))

#define EURO RALT(KC_2)





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CLMK] = LAYOUT_split_3x6_3(
        TO(QWER),_________________COLEMAK_L1________________,   _________________COLEMAK_R1________________, 	KC_NO,
        TO(NAV), _________________COLEMAK_L2________________,    _________________COLEMAK_R2________________, 	KC_NO,
        KC_NO,   _________________COLEMAK_L3________________,    _________________COLEMAK_R3________________,   KC_NO,
                                        ________________CALLUM_THUMBS______________
    ),

    [QWER] = LAYOUT_split_3x6_3(
        TO(CLMK),_________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, 	KC_NO,
        TO(NAV), _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, 	KC_NO,
        KC_NO,   _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________,   KC_NO,
                                        ________________CALLUM_THUMBS______________
    ),

    [SYM] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_GRAVE,       KC_AT,          KC_ASTR,        RALT(KC_3),     KC_SLASH,       			KC_NO,          MNE,     		NRC, 	    	KC_NO,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LPRN,        KC_RPRN,        KC_EXLM,        KC_QUES,        KC_COLN,		 			KC_NO,          ________________CALLUM_MODS_R______________,             KC_TRNS,
    KC_TRNS, KC_LBRACKET,    KC_RBRACKET,    KC_PERC,        KC_AMPR,        KC_SCOLON,     				KC_NO,          LALT(LCTL(LGUI(LSFT(KC_F16)))),LALT(LCTL(LGUI(LSFT(KC_F17)))),LALT(LCTL(LGUI(LSFT(KC_F18)))),LALT(LCTL(LGUI(LSFT(KC_F19)))),KC_TRNS,
													KC_TRNS, KC_TRNS, KC_BSPACE, 					KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NAV] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,   KC_MAC_REDO,     			KC_PGUP,        LALT(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),    LALT(KC_RIGHT), KC_TRNS,
    TO(DEF), ________________CALLUM_MODS_L______________,                   LGUI(KC_LEFT),                 	  		KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRNS,
    KC_TRNS, SW_WIN,  		SW_LANG, 		LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),LGUI(KC_RIGHT),				KC_CAPSLOCK,    LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),    LGUI(KC_RIGHT), KC_TRNS,
													KC_TRNS,  KC_TRNS, KC_TRNS, 			KC_ENTER,       KC_TRNS, KC_TRNS
    ),

    [NUM] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_TRNS, C(KC_E),        G(KC_S),        G(KC_N),        KC_AUDIO_VOL_UP,			KC_SLASH,       KC_7,   		KC_8,    		KC_9,    		KC_EQUAL,       KC_TRNS,
    KC_TRNS, ________________CALLUM_MODS_L______________,                   KC_AUDIO_VOL_DOWN,     		KC_ASTR,        KC_4,    		KC_5,    		KC_6,    		LSFT(KC_EQUAL), KC_TRNS,
    KC_TRNS, KC_ESCAPE,      KC_TAB,         KC_SPACE,       KC_ENTER,       KC_AUDIO_MUTE, 				KC_DOT,       	KC_1,    		KC_2,    		KC_3,    		KC_MINUS,       KC_TRNS,
													KC_TRNS,  KC_TRNS, KC_TRNS, 			KC_0, 		 	KC_TRNS, KC_TRNS
	),
  	[MOUSE] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         				KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRNS,
    KC_TRNS, ________________CALLUM_MODS_L______________,                   KC_NO,                      KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRNS,
    KC_TRNS, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          			KC_NO,          KC_MS_BTN3,     KC_MS_BTN1, 	KC_MS_BTN2,     KC_NO,          KC_TRNS,
													KC_TRNS,  KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS
	),
	[SYM2] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_LABK,        KC_RABK,        LSFT(KC_3),   	KC_DLR,         LALT(LSFT(UK_8)),			EURO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
    KC_TRNS, KC_BSLASH,      KC_SLASH,       KC_EQUAL,       KC_PLUS,        KC_PIPE,                    KC_NO,          ________________CALLUM_MODS_R______________,             KC_TRNS,
    KC_TRNS, KC_LCBR,        KC_RCBR,        UK_CIRC,        UK_BSLS,        UK_PIPE,        			KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRNS,
													KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS,  KC_TRNS
  	),

	[SETUP] = LAYOUT_split_3x6_3(
    RGB_TOG, 		RGB_SPI,        RGB_VAI,        RGB_HUI,        RGB_MOD,        RGB_SAI,        			SLEEP,          KC_MEDIA_PLAY_PAUSE, KC_NO,     KC_NO,          KC_NO,          RESET,
    KC_TRNS, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK, KC_NO,           KC_NO,          ________________CALLUM_MODS_R______________,             KC_TRNS,
    KC_TRNS, PWD,            PROJECT,     	KC_TRNS, KC_TRNS, KC_TRNS, 			KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRNS,
													KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS,  KC_TRNS
  ),

};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
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
    case LA_SYM:
    case LA_NAV:
    case LA_MOUSE:
    case LA_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LALT, KC_TAB, SW_LANG,
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
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

	switch(keycode) {
	case MNE: // all macros edited by Hugh to make them instant
		if (record->event.pressed) {
		  SEND_STRING("M&E");

		}
		break;
    case NRC:
		if (record->event.pressed) {
		  SEND_STRING("NRC");
		}
		break;
    case PROJECT:
		if (record->event.pressed) {
		  SEND_STRING("NOUA0007");
		}
		break;
    case PWD:
		if (record->event.pressed) {
		  SEND_STRING("setagergesed");
		}
		break;

	}




    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, SYM, NAV, SYM2);
  state = update_tri_layer_state(state, NUM, MOUSE, SETUP);
  return state;
}


void oled_render_layer_state_r2g_jwe(void) {
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
	     oled_write_P(PSTR("CAPS : "), false);
	} else {
    	oled_write_P(PSTR("Layer: "), false);
	}

    switch (get_highest_layer(layer_state)) {
        case CLMK:
            oled_write_P(PSTR("Colemak"), false);
            break;
        case QWERT:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case SYM:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Navigation"), false);
            break;
        case NUM:
            oled_write_P(PSTR("Numpad"), false);
            break;
        case SYM2:
            oled_write_P(PSTR("Sym2"), false);
            break;
        case MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case SETUP:
            oled_write_P(PSTR("Setup"), false);
            break;

    }
}

void render_bootmagic_status_r2g_jwe(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo_r2g_jwe(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(corne_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state_r2g_jwe();
        oled_advance_page(true);
        oled_advance_page(true);
        render_bootmagic_status_r2g_jwe(false); // should be isMyToggle if i actually enable it
    } else {
        oled_render_logo_r2g_jwe();
    }
    return false;
}
