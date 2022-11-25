// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// defined keycodes
#define JWE_WEB     S(A(C(G(KC_F16))))
#define JWE_OTLK    S(A(C(G(KC_F17))))
#define JWE_WORD    S(A(C(G(KC_F18))))
#define JWE_KEYS    S(A(C(G(KC_F19))))
// #define LA_SYM      OSL(SYM)
// #define LA_NAV      MO(NAV)
// #define LA_NUM      MO(NUM)
// #define LA_MOUSE    MO(MOUSE)

#define JWE_NXTAB   C(KC_TAB)
#define JWE_PRVTAB  C(S(KC_TAB))

#define BCKTICK     JWE_BSLS
#define TILDE       S(JWE_BSLS)
#define DEGREE      A(S(KC_8))
#define POUND       LSFT(KC_3)
#define CIRC        S(KC_6)

#ifdef ERGODOX 
#define JWE_BSLS    KC_GRV
#define SECTION     KC_NUBS
#else
#define JWE_BSLS    KC_NUBS
#define SECTION     KC_GRV
#endif // ERGODOX

#define ZM_MUTE     SCMD(KC_A)

#ifdef LEADER_ENABLE
#define LEAD        KC_LEAD
#endif
#ifdef USERSPACE_LEADER
#define LEAD        JWE_LEAD
#endif
#ifndef LEADER_ENABLE
#ifndef USERSPACE_LEADER
#define LEAD        MO(MOUSE)
#endif
#endif

//  MAC-ONLY keys
#ifdef MAC
#define SK_UNDO     G(KC_Z)
#define SK_CUT      G(KC_X)
#define SK_COPY     G(KC_C)
#define SK_PSTE     G(KC_V)
#define SK_REDO     G(KC_Y)
#define SK_EURO     RALT(KC_2)
#define SK_AT       S(KC_2)
#define SK_HASH     RALT(KC_3)
#define SK_WORDPRV  A(KC_LEFT)
#define SK_WORDNXT  A(KC_RIGHT)
#define SK_LINEBEG  G(KC_LEFT)
#define SK_LINEEND  G(KC_RIGHT)
#define SK_PARAPRV  A(KC_UP)
#define SK_PARANXT  A(KC_DOWN)
#define SK_WORDDEL  A(KC_DEL)
#define SK_WORDBSPC A(KC_BSPC)
#define JWE_DONE    C(KC_E)
#define SK_DOCBEG   G(KC_UP)
#define SK_DOCEND   G(KC_DOWN)
//#define SLEEP       S(C(KC_POWER))
//#define SLEEP       A(G(KC_POWER))
#endif // MAC

#ifdef YABAI
#define Y_ZOOM C(A(G(KC_Y)))
#define Y_WARP_L C(A(G(KC_U)))
#define Y_WARP_D C(A(G(KC_I)))
#define Y_WARP_U C(A(G(KC_O)))
#define Y_WARP_R C(A(G(KC_P)))
#define Y_TOGGL C(A(G(KC_M)))
#define Y_SPC_L C(KC_LEFT)
#define Y_APPWIN C(KC_DOWN)
#define Y_M_CTL C(KC_UP)
#define Y_SPC_R C(KC_RIGHT)
#define Y_CENTRE C(A(G(KC_H)))
#define Y_WIN_L C(A(G(KC_J)))
#define Y_WIN_D C(A(G(KC_K)))
#define Y_WIN_U C(A(G(KC_L)))
#define Y_WIN_R C(A(G(KC_SCLN)))
#endif // YABAI



// WINDOWS-ONLY keys
#ifdef WINDOWS
#define SK_UNDO     C(KC_Z)
#define SK_CUT      C(KC_X)
#define SK_COPY     C(KC_C)
#define SK_PSTE     C(KC_V)
#define SK_REDO     C(KC_Y)
#define SK_EURO     LCA(KC_4)
#define SK_AT       S(KC_QUOT)
#define SK_HASH     KC_BSLASH
#define SK_WORDPRV  C(KC_LEFT)
#define SK_WORDNXT  C(KC_RIGHT)
#define SK_LINEBEG  KC_HOME
#define SK_LINEEND  KC_END
#define SK_PARAPRV  C(KC_UP)
#define SK_PARANXT  C(KC_DOWN)
#define SK_DOCBEG   C(KC_UP),
#define SK_DOCEND   C(KC_DOWN)
#define SLEEP       KC_POWER
#define SK_WORDDEL  C(KC_DEL)
#define SK_WORDBSPC C(KC_BSPC)
#define JWE_DONE    C(S(KC_1))
#endif // WINDOWS



// wrappers
#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT
#define _________________COLEMAK_R2________________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINUS

#define __________________ENGRAM_L1________________       KC_B,    KC_Y,    KC_O,    KC_U,    KC_COMM
#define __________________ENGRAM_L2________________       KC_C,    KC_I,    KC_E,    KC_A,    KC_BSPC
#define __________________ENGRAM_L3________________       KC_G,    KC_X,    KC_J,    KC_K,    KC_QUOT

#define __________________ENGRAM_R1________________       KC_DOT,  KC_L,    KC_D,    KC_W,    KC_V
#define __________________ENGRAM_R2________________       KC_ENT,  KC_H,    KC_T,    KC_S,    KC_N
#define __________________ENGRAM_R3________________       KC_MINUS,KC_R,    KC_M,    KC_F,    KC_P

#ifdef QWERTY
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINUS
#endif // QWERTY




#define __TL1__ LA_NUM
#define __TL2__ LA_NAV
//#define __TL3__ JWE_SHFT
#define __TR1__ KC_SPC
#define __TR2__ OS_SYM
#define __TR3__ LA_MOUSE


#define __TL3__ OSM(MOD_LSFT)
/* #ifdef USERSPACE_CAPS_WORD */
/* #define __TL3__ JWE_SHFT */
/* #elif defined(CAPS_WORD_ENABLE) */
/* #define __TL3__ JWE_SHFT */
/* #else */
/* #define __TL3__ KC_LSFT */
/* #endif */

#define ________________CALLUM_THUMBS______________       __TL1__,  __TL2__,    __TL3__,    __TR1__,    __TR2__,    __TR3__

#define ________________CALLUM_MODS_L______________       OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT
#define ________________CALLUM_MODS_R______________       OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL

#define ________________BLANK_THUMBS_______________       _______, _______, _______, _______, _______, _______


/* JWE_PROJ */
/* POUND */
/* JWE_KEYS */

#define _________________SYMBOLS_L1________________       KC_LABK,  KC_LCBR,    KC_LPRN,    KC_LBRC,   KC_COMM 
#define _________________SYMBOLS_L2________________       SK_HASH,  KC_ASTR,    KC_EXLM,    KC_QUES,   KC_SLASH
#define _________________SYMBOLS_L3________________       KC_PERC,  SK_AT,      KC_AMPR,    KC_DLR,    BCKTICK

#define _________________SYMBOLS_R1________________       KC_DOT,   KC_RBRC,    KC_RPRN,    KC_RCBR,   KC_RABK
#define _________________SYMBOLS_R2________________       KC_BSLS,    ________________CALLUM_MODS_R______________
#ifdef LEADER_ENABLE
#define _________________SYMBOLS_R3________________       TILDE,    CIRC,       KC_LEAD,    JWE_NRC,   JWE_MNE
#endif
#ifdef USERSPACE_LEADER
#define _________________SYMBOLS_R3________________       TILDE,    CIRC,       JWE_LEAD,   JWE_NRC,   JWE_MNE
#endif
#ifndef LEADER_ENABLE
#ifndef USERSPACE_LEADER
#define _________________SYMBOLS_R3________________       TILDE,    CIRC,       KC_LEAD,    JWE_NRC,   JWE_MNE
#endif // USERSPACE_LEADER
#endif // LEADER_ENABLE


#define ___________________NAV_L1__________________       SK_UNDO,  SK_CUT,     SK_COPY,    SK_PSTE,    SK_REDO
#define ___________________NAV_L2__________________       ________________CALLUM_MODS_L______________,  SK_WORDBSPC
#define ___________________NAV_L3__________________       SW_WIN,   SW_AWIN,    KC_ESC,     KC_TAB,     SK_WORDDEL

#define ___________________NAV_R1__________________       KC_PGUP,  SK_WORDPRV, SK_PARANXT, SK_PARAPRV, SK_WORDNXT
#define ___________________NAV_R2__________________       KC_PGDN,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
#define ___________________NAV_R3__________________       KC_CAPS,  SK_LINEBEG, SK_DOCEND,  SK_DOCBEG,  SK_LINEEND



#define _________________NUMBERS_L1________________       KC_Q,     KC_W,       KC_VOLD,    KC_VOLU,    KC_COMM
#define _________________NUMBERS_L2________________       ________________CALLUM_MODS_L______________,  KC_BSPC
#define _________________NUMBERS_L3________________       JWE_PRVTAB,JWE_NXTAB, KC_ESC,    KC_TAB,      KC_MUTE

#define _________________NUMBERS_R1________________       KC_DOT,   KC_7,       KC_8,       KC_9,       KC_EQUAL
#define _________________NUMBERS_R2________________       KC_ENT,   KC_4,       KC_5,       KC_6,       KC_0 
#define _________________NUMBERS_R3________________       KC_MINUS, KC_1,       KC_2,       KC_3,       KC_PLUS



#define __________________MOUSE_L1_________________       KC_WH_L,  KC_WH_U,    KC_WH_D,    KC_WH_R,    KC_BTN2
#define __________________MOUSE_L2_________________       KC_MS_L,  KC_MS_U,    KC_MS_D,    KC_MS_R,    KC_BTN1
#define __________________MOUSE_L3_________________       KC_MPRV,  KC_MSTP,    KC_MPLY,    KC_MNXT,    KC_BTN3

#ifndef YABAI
#define __________________MOUSE_R1_________________       KC_BTN3,  KC_BTN1,    KC_BTN2,    KC_NO,      KC_NO
#define __________________MOUSE_R2_________________       KC_NO,    ________________CALLUM_MODS_R______________
#define __________________MOUSE_R3_________________       KC_NO,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
#endif // YABAI

#ifdef YABAI
#define __________________MOUSE_R1_________________       Y_ZOOM,   Y_WARP_L,  Y_WARP_D,    Y_WARP_U,   Y_WARP_R
#define __________________MOUSE_R2_________________       Y_TOGGL,  Y_SPC_L,   Y_APPWIN,    Y_M_CTL,    Y_SPC_R
#define __________________MOUSE_R3_________________       Y_CENTRE, Y_WIN_L,   Y_WIN_D,     Y_WIN_U,    Y_WIN_R
#endif // YABAI




#define __________________SYM_2_L1_________________       KC_LABK,  KC_RABK,    SK_EURO,    DEGREE,     _______
#define __________________SYM_2_L2_________________       KC_LBRC,  KC_RBRC,    KC_PIPE,    TILDE,      _______
#define __________________SYM_2_L3_________________       KC_LCBR,  KC_RCBR,    CIRC,       SECTION,    _______

#define __________________SYM_2_R1_________________       RGB_MOD,  RGB_VAI,    RGB_HUI,    RGB_SAI,    RGB_SPI
#define __________________SYM_2_R2_________________       RGB_TOG,  ________________CALLUM_MODS_R______________
#ifndef LEADER_ENABLE
#ifndef USERSPACE_LEADER
#define __________________SYM_2_R3_________________       JWE_PWD,  KC_ENTER,   KC_NO,      KC_NO,      JWE_TOGG
#endif
#endif
#ifdef LEADER_ENABLE
#define __________________SYM_2_R3_________________       KC_NO,    KC_NO,      KC_NO,      KC_NO,      JWE_TOGG
#endif
#ifdef USERSPACE_LEADER
#define __________________SYM_2_R3_________________       KC_NO,    KC_NO,      KC_NO,      KC_NO,      JWE_TOGG
#endif


#define ___________________FUNC_L1_________________       QK_BOOT,  QK_REBOOT,  QK_MAKE,    KC_NO,      KC_NO
#define ___________________FUNC_L2_________________       ________________CALLUM_MODS_L______________,  KC_NO
#define ___________________FUNC_L3_________________       KC_LEFT,  KC_UP,      KC_DOWN,    KC_RIGHT,   KC_NO

#define ___________________FUNC_R1_________________       KC_F12,   KC_F7,      KC_F8,      KC_F9,      KC_NO
#define ___________________FUNC_R2_________________       KC_F11,   KC_F4,      KC_F5,      KC_F6,      KC_NO
#define ___________________FUNC_R3_________________       KC_F10,   KC_F1,      KC_F2,      KC_F3,      SLEEP


#define _ALPHAS_COLEMAK \
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________, \
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________, \
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________

#define _ALPHAS_ENGRAM \
    __________________ENGRAM_L1________________, __________________ENGRAM_R1________________, \
    __________________ENGRAM_L2________________, __________________ENGRAM_R2________________, \
    __________________ENGRAM_L3________________, __________________ENGRAM_R3________________
#ifdef QWERTY
#define _ALPHAS_QWERTY \
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, \
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, \
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
#endif // QWERTY
#define _ALPHAS_NUMBERS \
    _________________NUMBERS_L1________________, _________________NUMBERS_R1________________, \
    _________________NUMBERS_L2________________, _________________NUMBERS_R2________________, \
    _________________NUMBERS_L3________________, _________________NUMBERS_R3________________
#define _ALPHAS_SYMBOLS \
    _________________SYMBOLS_L1________________, _________________SYMBOLS_R1________________, \
    _________________SYMBOLS_L2________________, _________________SYMBOLS_R2________________, \
    _________________SYMBOLS_L3________________, _________________SYMBOLS_R3________________
#define _ALPHAS_NAV \
    ___________________NAV_L1__________________, ___________________NAV_R1__________________, \
    ___________________NAV_L2__________________, ___________________NAV_R2__________________, \
    ___________________NAV_L3__________________, ___________________NAV_R3__________________
#define _ALPHAS_MOUSE \
    __________________MOUSE_L1_________________, __________________MOUSE_R1_________________, \
    __________________MOUSE_L2_________________, __________________MOUSE_R2_________________, \
    __________________MOUSE_L3_________________, __________________MOUSE_R3_________________
#define _ALPHAS_SYM2 \
    __________________SYM_2_L1_________________, __________________SYM_2_R1_________________, \
    __________________SYM_2_L2_________________, __________________SYM_2_R2_________________, \
    __________________SYM_2_L3_________________, __________________SYM_2_R3_________________
#define _ALPHAS_FUNC \
    ___________________FUNC_L1_________________, ___________________FUNC_R1_________________, \
    ___________________FUNC_L2_________________, ___________________FUNC_R2_________________, \
    ___________________FUNC_L3_________________, ___________________FUNC_R3_________________



#define _LAYOUT_5x3_TO_6x3( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, \
  k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, \
  k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A \
    ) \
    ZM_MUTE,  k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, KC_Q, \
    LEAD,     k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, KC_Z, \
    TO(ENGRAM), k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, TO(CLMK)
#define LAYOUT_5x3_TO_6x3(...) _LAYOUT_5x3_TO_6x3(__VA_ARGS__)

#define _LAYOUT_ADD_THUMBS(...) __VA_ARGS__, ________________CALLUM_THUMBS______________
#define LAYOUT_ADD_THUMBS(...) _LAYOUT_ADD_THUMBS(__VA_ARGS__)

#define _LAYOUT_ergodox_wrapper( \
    k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, \
                   k31, k32, k33, k34, k35, k36                 \
  ) \
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,        KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, \
      k01,    k02,  k03,  k04,  k05,  k06,  KC_NO,        KC_NO, k07,  k08,  k09,  k0A,  k0B,  k0C,     \
      k11,    k12,  k13,  k14,  k15,  k16,                       k17,  k18,  k19,  k1A,  k1B,  k1C,     \
      k21,    k22,  k23,  k24,  k25,  k26,  KC_NO,        KC_NO, k27,  k28,  k29,  k2A,  k2B,  k2C,     \
      KC_NUBS,  KC_NO,KC_NO,KC_NO,k31,                                   k36,  KC_NO,KC_NO,KC_NO,KC_NO,   \
                                      KC_NO,KC_NO,        KC_NO, KC_NO,                                 \
                                            KC_NO,        KC_NO,                                        \
                                k32,  k33,  KC_NO,        KC_NO, k34,  k35
#define LAYOUT_ergodox_wrapper(...) _LAYOUT_ergodox_wrapper(__VA_ARGS__)
