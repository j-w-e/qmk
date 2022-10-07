// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MAC
/* #define BOTH */
#define YABAI
#define MASTER_LEFT
#define ERGODOX

#define LAYERLIGHTS


#ifdef USERSPACE_LEADER
#define LEADER_DISPLAY_STR
#endif

#ifdef USERSPACE_CAPS_WORD
#define USE_XCASE
// #define CAPSWORD_USE_SHIFT
#endif

#define USERSPACE_CUSTOM_DOT_COMMA

#ifdef CAPS_WORD_ENABLE
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#endif

/* #define QWERTY */
#define COLEMAK

#define ENABLE_COMPILE_KEYCODE
