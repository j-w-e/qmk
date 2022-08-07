/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/


#define ERGODOX
// #undef HSV_PURPLE
#define JWE_PURPLE 175, 255, 255

#define BOTH
#define YABAI

#define LAYERLIGHTS

#ifdef USERSPACE_CAPS_WORD
#define USE_XCASE
// #define CAPSWORD_USE_SHIFT
#endif

#define QWERTY
#define USERSPACE_CUSTOM_DOT_COMMA

#define ENABLE_COMPILE_KEYCODE
