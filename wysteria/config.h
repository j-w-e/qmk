// Copyright 2023 j-w-e (@j-w-e)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_LED_COUNT 36
#    define RGB_MATRIX_SPLIT { 18, 18 }
/* #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50 */
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_CENTER { 112, 64 }
#endif

/* #define OLED_DC_PIN GP3 */
/* #define OLED_CS_PIN GP2 */
#define I2C1_SCL_PIN        GP3
#define I2C1_SDA_PIN        GP2
/* #define I2C_DRIVER I2CD0 */

#define ENCODERS_PAD_A { GP9 }
#define ENCODERS_PAD_B { GP8 }

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


