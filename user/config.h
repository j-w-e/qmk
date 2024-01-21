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

#if defined(WPM_ENABLE)
#    define WPM_LAUNCH_CONTROL
// #    define WPM_UNFILTERED
#    define WPM_ALLOW_COUNT_REGRESSION
#    define WPM_SAMPLE_SECONDS      10
#    define WPM_SAMPLE_PERIODS      50
// #    define WPM_ESTIMATED_WORD_SIZE 5
#endif


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
# 	define RGB_DISABLE_TIMEOUT 900000 // number of milliseconds to wait until rgb automatically turns off
#	define RGB_MATRIX_KEYPRESSES
#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS         // Static dual hue, speed is hue for secondary hue
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom, speed controls how much gradient changes
#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
#   undef ENABLE_RGB_MATRIX_BREATHING           // Single hue brightness cycling animation
#   undef ENABLE_RGB_MATRIX_BAND_SAT        // Single hue band fading saturation scrolling left to right
#   undef ENABLE_RGB_MATRIX_BAND_VAL        // Single hue band fading brightness scrolling left to right
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
#   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right
#   undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
#   define ENABLE_RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
#   undef ENABLE_RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
#   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
#   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halfs of keyboard
#   undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
#   define ENABLE_RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
#   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
#   undef ENABLE_RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight ammount at the same time, then shifts back
#   undef ENABLE_RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight ammount in a wave to the right, then back to the left
#   undef ENABLE_RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight ammount and then back down in a wave to the right
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL       // Single hue fractal filled keys pulsing horizontally out to edges
#   define ENABLE_RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
#   undef ENABLE_RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
#   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE      // Static single hue, pulses keys hit to shifted hue then fades to current hue
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#   undef ENABLE_RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
#   undef ENABLE_RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
#   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out
#   undef ENABLE_RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness, maintaining user set color
#   undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
#   undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
#   undef ENABLE_RGB_MATRIX_RIVERFLOW           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 100 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE
#define RGB_MATRIX_DEFAULT_SPD 10
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
/* #define RGB_MATRIX_REST_MODE RGB_MATRIX_CYCLE_OUT_IN_DUAL */
#define RGB_MATRIX_REST_MODE RGB_MATRIX_CYCLE_OUT_IN
#endif

#ifdef OLED_ENABLE
#define OLED_FONT_H "_jwe_font.c"
/* #define OLED_SCROLL_TIMEOUT 30000 */
/* #define OLED_SCROLL_TIMEOUT_RIGHT */
/* #define OLED_FADE_OUT */
/* #define OLED_FADE_OUT_INTERVAL 2 */
#define OLED_BRIGHTNESS 128
#define OLED_TIMEOUT 15000
#define SPLIT_OLED_ENABLE
#endif

#define SPLIT_ACTIVITY_ENABLE
#define KEYBOARD_IDLE_TIME 5000
#define KEYBOARD_SLEEP_TIME 10000
#define SPLIT_TRANSACTION_IDS_USER SYNC_RGB_STATE

//#define SPLIT_LAYER_STATE_ENABLE
#define LAYER_STATE_8BIT // limit to fewer than 8 layers
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended


#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
/* #define NO_ACTION_ONESHOT */
/* #define NO_ACTION_TAPPING */

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 25
/* #define COMBO_MUST_TAP_PER_COMBO */

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 150
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
#endif //LEADER_ENABLE
