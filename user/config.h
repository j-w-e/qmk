// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 250

#ifdef CAPS_WORD_ENABLE
#undef CAPS_WORD_IDLE_TIMEOUT
#define CAPS_WORD_IDLE_TIMEOUT 1000
#endif

#define USB_SUSPEND_WAKEUP_DELAY 0

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 101

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 50

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 2


#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LIMIT_VAL 192

#   undef RGBLIGHT_EFFECT_BREATHING
#   undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#   undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#   undef RGBLIGHT_EFFECT_SNAKE
#   define RGBLIGHT_EFFECT_KNIGHT
#   undef RGBLIGHT_EFFECT_CHRISTMAS
#   undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#   undef RGBLIGHT_EFFECT_RGB_TEST
#   undef RGBLIGHT_EFFECT_ALTERNATING
#   undef RGBLIGHT_EFFECT_TWINKLE

#endif

#ifdef RGB_MATRIX_ENABLE
//# 	define RGB_DISABLE_TIMEOUT 60000 // number of milliseconds to wait until rgb automatically turns off
#	define RGB_MATRIX_KEYPRESSES
#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_BREATHING
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL
#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   undef ENABLE_RGB_MATRIX_RAINDROPS
#   undef ENABLE_RGB_MATRIX_HUE_BREATHING
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   undef ENABLE_RGB_MATRIX_SPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#endif

#ifdef OLED_ENABLE
#define OLED_FONT_H "_jwe_font.c"
#define OLED_SCROLL_TIMEOUT 5000
#define OLED_BRIGHTNESS 128
//#define OLED_SCROLL_TIMEOUT_RIGHT
#define OLED_TIMEOUT 20000
#endif


//#define SPLIT_LAYER_STATE_ENABLE
#define LAYER_STATE_8BIT // limit to fewer than 8 layers
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended




#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
/* #define NO_ACTION_ONESHOT */
/* #define NO_ACTION_TAPPING */

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 40
#define COMBO_MUST_TAP_PER_COMBO

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 150
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
#endif //LEADER_ENABLE
