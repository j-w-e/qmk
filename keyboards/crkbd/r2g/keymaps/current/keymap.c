#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_uk.h"
#include "caps_word.h" //added by Hugh for caps_word


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
	
enum custom_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,

  MY_LAYER_SWITCH, // Added by HUGH to toggle a layer that doesn't have home-row mods
  MY_TOGG, // ADDED BY HUGH
  SLEEP, 
  PWD,

};

enum tap_dance_codes {
  DANCE_0,
  DANCE_13,
};


bool is_actively_typing = false; // added by HUGH to manage a timer to flick back to the default layer if not actively typing fast
uint16_t actively_typing = 0; // added by HUGH as above

bool isMyToggle = false; // ADDED BY HUGH to keep track of Mac (false) or Win (true) layout. Changes only left side of the board, swapping Ctrl and GUI


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {    // EDITED BY HUGH to add MY_TOGG to layer 7, and MY_LAYER_SWITCH to layer 4. Changed base layer to remove the dual function of dot, so that the dot can shift to colon
  [0] = LAYOUT_split_3x6_3(
    KC_ESCAPE, 		KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           	 		KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_TRANSPARENT,
    KC_TAB,  		LCTL_T(KC_A),   LALT_T(KC_R),   LGUI_T(KC_S),   LSFT_T(KC_T),   KC_G,                       KC_M,           RSFT_T(KC_N),   LGUI_T(KC_E),   LALT_T(KC_I),   LCTL_T(KC_O),   KC_TRANSPARENT,
    KC_NO, 			KC_Z,           RALT_T(KC_X),   KC_C,           KC_D,           KC_V,           			KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_TRANSPARENT,
													LT(3,KC_TAB),   LT(2,KC_BSPACE),OSM(MOD_LSFT), LT(7,KC_ENTER), LT(6,KC_SPACE), OSL(4)
  ),
  [1] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 			KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_R,           KC_S,           KC_T,           KC_TRANSPARENT,             KC_TRANSPARENT, KC_N,           KC_E,           KC_I,           KC_O,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_X,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 			KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT,
													KC_TRANSPARENT, TD(DANCE_0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,   LGUI(KC_Y),     			KC_PGUP,        LALT(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),    LALT(KC_RIGHT), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,      LGUI(KC_LEFT),     	  		KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_WH_LEFT,  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),KC_MS_WH_RIGHT, LGUI(KC_RIGHT),				KC_CAPSLOCK,    LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),    LGUI(KC_RIGHT), KC_TRANSPARENT,
													KC_NO,          KC_TRANSPARENT, KC_NO,         KC_ENTER,       KC_SPACE, KC_DELETE
  ),
  [3] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, C(KC_E),        G(KC_S),        G(KC_N),        KC_AUDIO_VOL_UP,			KC_SLASH,       KC_7,   		KC_8,    		KC_9,    		KC_LPRN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,      KC_AUDIO_VOL_DOWN,     		KC_ASTR,        KC_4,    		KC_5,    		KC_6,    		KC_RPRN,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ESCAPE,      KC_RALT,        KC_SPACE,       KC_ENTER,       KC_AUDIO_MUTE, 				KC_MINUS,       KC_1,    		KC_2,    		KC_3,    		KC_EQUAL,       KC_TRANSPARENT,
													KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_EQUAL),   KC_0, KC_DOT
  ),
  [4] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_GRAVE,       KC_AT,          KC_ASTR,        RALT(KC_3),     KC_SLASH,       			KC_NO,          ST_MACRO_0,     ST_MACRO_1,     KC_NO,          MY_LAYER_SWITCH,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_EXLM,        KC_QUES,        KC_COLN,		 			KC_NO,          KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_PERC,        KC_AMPR,        KC_SCOLON,     				KC_NO,          LALT(LCTL(LGUI(LSFT(KC_F16)))),LALT(LCTL(LGUI(LSFT(KC_F17)))),LALT(LCTL(LGUI(LSFT(KC_F18)))),LALT(LCTL(LGUI(LSFT(KC_F19)))),KC_TRANSPARENT,
													KC_DELETE,      KC_TRANSPARENT, MO(5),         KC_TRANSPARENT, KC_TRANSPARENT, KC_NO
  ),
  [5] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         				KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,      KC_NO,                      KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          			KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
													KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_BTN1, KC_MS_BTN2
  ),
  [6] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_LABK,        KC_RABK,        TD(DANCE_13),   KC_DLR,         LALT(LSFT(UK_8)),			KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_BSLASH,      KC_SLASH,       KC_EQUAL,       KC_PLUS,        KC_PIPE,                    KC_NO,          KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        UK_CIRC,        UK_BSLS,        UK_PIPE,        			KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT,
													KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT
  ),
  [7] = LAYOUT_split_3x6_3(
    RGB_TOG, 		RGB_SPI,        RGB_VAI,        RGB_HUI,        RGB_MOD,        RGB_SAI,        			KC_NO,          SLEEP,          KC_NO,          KC_NO,          KC_NO,          RESET,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK, KC_NO,           KC_NO,          KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_TRANSPARENT,
    KC_TRANSPARENT, PWD,            ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT, 			KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          MY_TOGG,
													KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_NO,  KC_TRANSPARENT
  ),
};


bool suspended = false;
uint8_t mod_state;  // added by Hugh for MY_DOT and MY_COMMA
uint8_t OSmod_state;  // added by Hugh for MY_DOT and MY_COMMA
bool NOMODS = false;




enum Layers{
    L_BASE, L_NO_MODS, L_NAV, L_NUM, L_SYM, L_MOUSE, L_SYM2, L_SETUP
};

void oled_render_layer_state_r2g_jwe(void) {
    
   	NOMODS = layer_state_is(L_NO_MODS);

    
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
	     oled_write_P(PSTR("CAPS : "), NOMODS);
	} else {
    	oled_write_P(PSTR("Layer: "), NOMODS);
	}

    //oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_P(PSTR("Colemak"), NOMODS);
            break;
        case L_NO_MODS:
            oled_write_P(PSTR("No mods"), NOMODS);
            break;
        case L_NAV:
            oled_write_P(PSTR("Navigation"), NOMODS);
            break;
        case L_NUM:
            oled_write_P(PSTR("Numpad"), NOMODS);
            break;
        case L_SYM:
            oled_write_P(PSTR("Symbols"), NOMODS);
            break;
        case L_MOUSE:
            oled_write_P(PSTR("Mouse"), NOMODS);
            break;
        case L_SYM2:
            oled_write_P(PSTR("Sym2"), NOMODS);
            break;
        case L_SETUP:
            oled_write_P(PSTR("Setup"), NOMODS);
            break;
    }
}

/*const char code_to_name_r2g_jwe[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

char key_name_r2g_jwe = ' ';
uint16_t last_keycode_r2g;
uint8_t last_row_r2g;
uint8_t last_col_r2g;

void set_keylog_r2g_jwe(uint16_t keycode, keyrecord_t *record) {
    key_name_r2g_jwe = ' ';
    last_keycode_r2g = keycode;
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { last_keycode_r2g = keycode & 0xFF; }
    if (keycode < 60) {
      key_name_r2g_jwe = code_to_name_r2g_jwe[keycode];
    }
    last_row_r2g = record->event.key.row;
    last_col_r2g = record->event.key.col;
}

const char *depad_str_jwe(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char) ++depad_str;
    return depad_str;
}

void oled_render_keylog_r2g_jwe(void) {
    //oled_write(keylog_str_r2g, false);
    const char *last_row_r2g_str = get_u8_str(last_row_r2g, ' ');
    oled_write(depad_str_jwe(last_row_r2g_str, ' '), false);
    oled_write_P(PSTR("x"), false);
    const char *last_col_r2g_str = get_u8_str(last_col_r2g, ' ');
    oled_write(depad_str_jwe(last_col_r2g_str, ' '), false);
    oled_write_P(PSTR(", k"), false);
    const char *last_keycode_r2g_str = get_u16_str(last_keycode_r2g, ' ');
    oled_write(depad_str_jwe(last_keycode_r2g_str, ' '), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name_r2g_jwe, false);
}*/

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
    //oled_set_cursor(oled_max_chars()/2,oled_max_lines()/2);
    //oled_write_P(PSTR("R2G"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state_r2g_jwe();
        oled_advance_page(true);
        /*if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)){
	        oled_write_P(PSTR("CAPS"), false);
	    } else {
            oled_write_P(PSTR("       "), false);
	    }*/
        //oled_render_keylog_r2g_jwe();
        oled_advance_page(true);
        render_bootmagic_status_r2g_jwe(isMyToggle);
    } else {
        oled_render_logo_r2g_jwe();
    }
    return false;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) { // entire function added by HUGH at this stage.


	if (!process_caps_word(keycode, record)) { return false; }  //added by Hugh for caps_word 
	//if (record->event.pressed) { set_keylog_r2g_jwe(keycode, record); } // added by Hugh for displaying the keycode on the oled screen (straight from the r2g code, adapted for _user functions, not _kb functions)


  mod_state = get_mods();
  OSmod_state = get_oneshot_mods();

  switch (keycode) {
    case ST_MACRO_0: // all macros edited by Hugh to make them instant
    if (record->event.pressed) {
      SEND_STRING("M&E");

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING("NRC");
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING("NOUA0007");
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING("TRUE");
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING("FALSE");
    }
    break;
    case PWD:
    if (record->event.pressed) {
      SEND_STRING("setagergesed");
    }
    break;
    

    // ADDED BY HUGH
    case MY_TOGG:
      if (record->event.pressed) {
        if (isMyToggle) {
          keymap_config.swap_lctl_lgui = false;
          isMyToggle = false;
        }
        else {
          keymap_config.swap_lctl_lgui = true;
          isMyToggle = true;
        }
      }
      else { // do nothing specific on key-up
      }
      return false;
      

    case MY_LAYER_SWITCH:
      if (record->event.pressed) {
        if (is_actively_typing) {
          layer_off(1);
          is_actively_typing = false;
        } else {
          actively_typing = timer_read();
          layer_on(1);
          is_actively_typing = true;
        }

      } else {}
      return false;

    case SLEEP: 
    	tap_code16(S(C(KC_POWER)));
    	return false;

	
    case KC_DOT:  // added by HUGH to allow for dot and comma, when shifted, to output : and ;
    {
    	static bool dotkey_registered;

        if (is_actively_typing) {
	      actively_typing = timer_read();
	    }
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                register_code(KC_SCLN);
                dotkey_registered = true;
                return false;
            } else if (OSmod_state & MOD_MASK_SHIFT) {
        		register_code(KC_SCLN);
                dotkey_registered = true;
                clear_oneshot_mods();
                return false;
            }
        } else {
            // Detect the activation of either shift keys
            if (dotkey_registered) {
                unregister_code(KC_SCLN);
                dotkey_registered = false;
                return false;
            }
        }

        return true;
    }
    case KC_COMMA:
    {
    	static bool dotkey_registered;

        if (is_actively_typing) {
	      actively_typing = timer_read();
	    }
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_SCLN);
                dotkey_registered = true;
                set_mods(mod_state);
                return false;
            } else if (OSmod_state & MOD_MASK_SHIFT) {
        		del_oneshot_mods(MOD_MASK_SHIFT);
        		register_code(KC_SCLN);
                dotkey_registered = true;
                clear_oneshot_mods();
                return false;
            }
        } else {
            // Detect the activation of either shift keys
            if (dotkey_registered) {
                unregister_code(KC_SCLN);
                dotkey_registered = false;
                return false;
            }
        }

        return true;
    } 

    default:
      if (is_actively_typing) {
	    actively_typing = timer_read();
	  }

  }
  return true;
}

/*
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCLN);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_key_override,
    &dot_key_override,
    NULL // Null terminate the array of overrides!
};
*/


void matrix_scan_user(void) {  // added by HUGH to automatically fall back to base layer if not actively typing
  if (is_actively_typing) {
    if (timer_elapsed(actively_typing) >  5000) {
      layer_off(1);
      is_actively_typing = false;
    }
  }
}


/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {  // added by HUGH to increase the tapping term of specifically the one-shot shift
    switch (keycode) {
        case OSM(MOD_LSFT):
            return TAPPING_TERM + 250;
        default:
            return TAPPING_TERM;
    }
}*/

/*uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    switch (layer) {
      case 0:
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(177,255,239);
        break;
      case 1:
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(1);
          rgblight_sethsv_noeeprom(43,253,255);
        break;
      default:
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;

};*/

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
  //oled_scroll_set_speed(4);
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[14];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_BSPACE));
        tap_code16(LALT(KC_BSPACE));
        tap_code16(LALT(KC_BSPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_BSPACE));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(KC_BSPACE)); break;
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: register_code16(LALT(KC_BSPACE)); register_code16(LALT(KC_BSPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_BSPACE)); register_code16(LALT(KC_BSPACE));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_BSPACE)); break;
        case SINGLE_HOLD: layer_off(2); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_BSPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_BSPACE)); break;
    }
    dance_state[0].step = 0;
}

void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_3));
        tap_code16(LSFT(KC_3));
        tap_code16(LSFT(KC_3));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_3));
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_3)); break;
        case DOUBLE_TAP: register_code16(RALT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_3)); register_code16(LSFT(KC_3));
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_3)); break;
        case DOUBLE_TAP: unregister_code16(RALT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_3)); break;
    }
    dance_state[13].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
};
