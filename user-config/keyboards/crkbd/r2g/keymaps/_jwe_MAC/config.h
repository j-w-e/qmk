/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/


#pragma once

// #define MAC
#define BOTH
#define YABAI
// #define MASTER_LEFT
#define EE_HANDS

#define LAYERLIGHTS
// #define BONGOCAT

#ifdef USERSPACE_LEADER
#define LEADER_DISPLAY_STR
#endif

#define QWERTY

#ifdef USERSPACE_CAPS_WORD
#define USE_XCASE
// #define CAPSWORD_USE_SHIFT
#endif

#define USERSPACE_CUSTOM_DOT_COMMA

#ifdef CAPS_WORD_ENABLE
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#endif

#define ENABLE_COMPILE_KEYCODE

