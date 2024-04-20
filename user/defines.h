// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

enum userspace_layers {
    APTMAK = 0,
    ENGRAM,
    NAV,
    NUM,
    MOUSE,
    SYM,
    SYM2,
    FUNC,
};

enum userspace_custom_keycodes {
    // Callum custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    OS_SYM,

    LA_NAV,
    LA_NUM,
    LA_MOUSE,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_AWIN, // Switch to next window within an app (cmd-grave, for macos)

    JWE_PROJ,
    JWE_MNE,
    JWE_NRC,
    SLEEP,

};

#define JWE_NXTAB   C(KC_TAB)
#define JWE_PRVTAB  C(S(KC_TAB))

#define BCKTICK     KC_GRV
#define SECTION     KC_NUBS
#define TILDE       S(BCKTICK)
#define DEGREE      A(S(KC_8))
#define POUND       LSFT(KC_3)
#define CIRC        S(KC_6)
#define EURO     RALT(KC_2)

#define SK_UNDO     G(KC_Z)
#define SK_CUT      G(KC_X)
#define SK_COPY     G(KC_C)
#define SK_PSTE     G(KC_V)
#define SK_REDO     G(KC_Y)
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
#define SK_DOCBEG   G(KC_UP)
#define SK_DOCEND   G(KC_DOWN)

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
#define Y_CENTRE C(A(G(KC_Z)))
#define Y_WIN_L C(A(G(KC_J)))
#define Y_WIN_D C(A(G(KC_K)))
#define Y_WIN_U C(A(G(KC_L)))
#define Y_WIN_R C(A(G(KC_SCLN)))

// wrappers
#define __TL1__ LA_NUM
#define __TL2__ LA_NAV
#define __TL3__ OSM(MOD_LSFT)
#define __TR1__ KC_SPC
#define __TR2__ OS_SYM
#define __TR3__ LA_MOUSE

#define ________________CALLUM_THUMBS______________       __TL1__,  __TL3__,    __TL2__,    __TR2__,    __TR1__,    __TR3__
#define ________________aptmak_THUMBS______________       __TL1__,  __TR1__,    __TL2__,    __TR2__,       KC_E,    __TR3__
#define _________________wyst_THUMBS_______________       __TL1__,  __TR1__,    __TL2__, KC_MUTE, KC_MUTE,  __TR2__,  KC_E,  __TR3__

#define ________________CALLUM_MODS_L______________       OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT
#define ________________CALLUM_MODS_R______________       OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL

#define ________________BLANK_THUMBS_______________       _______, _______, _______, _______, _______, _______


#define __________________APTMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT
#define __________________APTMAK_R2________________       KC_BSPC,  KC_N,    KC_A,    KC_I,    KC_O
#define __________________APTMAK_R3________________       KC_V,    KC_M,    KC_COMM, KC_DOT,  KC_MINUS

#define __________________APTMAK_L1________________       QK_REP,  KC_W,    KC_F,    KC_P,    KC_B
#define __________________APTMAK_L2________________       KC_R,    KC_S,    KC_T,    KC_H,    KC_ENT
#define __________________APTMAK_L3________________       KC_SLASH,KC_C,    KC_G,    KC_D,    KC_K

#define __________________ENGRAM_L1________________       KC_B,    KC_Y,    KC_O,    KC_U,    KC_COMM
#define __________________ENGRAM_L2________________       KC_C,    KC_I,    KC_E,    KC_A,    KC_NO
#define __________________ENGRAM_L3________________       KC_G,    KC_X,    KC_J,    KC_K,    KC_QUOT

#define __________________ENGRAM_R1________________       KC_DOT,  KC_L,    KC_D,    KC_W,    KC_V
#define __________________ENGRAM_R2________________       KC_BSPC, KC_H,    KC_T,    KC_S,    KC_N
#define __________________ENGRAM_R3________________       KC_MINUS,KC_R,    KC_M,    KC_F,    KC_P


#define _________________SYMBOLS_L1________________       KC_SLASH, KC_LCBR,    KC_LPRN,    KC_LBRC,   KC_LABK
#define _________________SYMBOLS_L2________________       SK_HASH,  KC_ASTR,    KC_EXLM,    KC_QUES,   KC_SLASH
#define _________________SYMBOLS_L3________________       KC_PERC,  SK_AT,      KC_DLR,     KC_AMPR,   BCKTICK

#define _________________SYMBOLS_R1________________       KC_RABK,  KC_RBRC,    KC_RPRN,    KC_RCBR,   KC_BSLS
#define _________________SYMBOLS_R2________________       SK_WORDBSPC,    ________________CALLUM_MODS_R______________
#define _________________SYMBOLS_R3________________       TILDE,    CIRC,       QK_LEAD,    JWE_NRC,   JWE_MNE


#define ___________________NAV_L1__________________       SK_UNDO,  SK_CUT,     SK_COPY,    SK_PSTE,    SK_REDO
#define ___________________NAV_L2__________________       ________________CALLUM_MODS_L______________,  KC_NO
#define ___________________NAV_L3__________________       SW_WIN,   SW_AWIN,    KC_ESC,     KC_TAB,     KC_NO

#define ___________________NAV_R1__________________       KC_PGUP,  SK_WORDPRV, SK_PARANXT, SK_PARAPRV, SK_WORDNXT
#define ___________________NAV_R2__________________       KC_PGDN,  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
#define ___________________NAV_R3__________________       _______,  SK_LINEBEG, SK_DOCEND,  SK_DOCBEG,  SK_LINEEND


#ifdef ERGODOX
#define _________________NUMBERS_L1________________       KC_E,     KC_W,       KC_VOLD,    KC_VOLU,    KC_MUTE
#else
#define _________________NUMBERS_L1________________       KC_E,     KC_W,       KC_NO,      SECTION,    KC_SPACE
#endif // ERGODOX
#define _________________NUMBERS_L2________________       OSM(MOD_LCTL),  OSM(MOD_LALT),    OSM(MOD_LGUI),    OSM(MOD_LSFT),    KC_ENT
/* #define _________________NUMBERS_L2________________       KC_LCTL,  KC_LALT,    KC_LGUI,    KC_LSFT,    KC_BSPC */
/* #define _________________NUMBERS_L2________________       ________________CALLUM_MODS_L______________,  KC_BSPC */
#define _________________NUMBERS_L3________________       JWE_PRVTAB,JWE_NXTAB, KC_ESC,    KC_TAB,      KC_COMM

#define _________________NUMBERS_R1________________       KC_MINUS, KC_7,       KC_8,       KC_9,       KC_EQUAL
#define _________________NUMBERS_R2________________       KC_BSPC,  KC_4,       KC_5,       KC_6,       KC_0
#define _________________NUMBERS_R3________________       KC_DOT,   KC_1,       KC_2,       KC_3,       KC_PLUS


#ifdef ERGODOX
#define __________________MOUSE_L1_________________       KC_WH_L,  KC_WH_U,    KC_WH_D,    KC_WH_R,    KC_BTN2
#define __________________MOUSE_L2_________________       KC_MS_L,  KC_MS_U,    KC_MS_D,    KC_MS_R,    KC_BTN1
#else
#define __________________MOUSE_L1_________________       KC_MS_L,  KC_MS_U,    KC_MS_D,    KC_MS_R,    KC_BTN2
#define __________________MOUSE_L2_________________       ________________CALLUM_MODS_L______________,  KC_BTN1
#endif // ERGODOX
#define __________________MOUSE_L3_________________       KC_MPRV,  KC_MSTP,    KC_MPLY,    KC_MNXT,    KC_BTN3

#define __________________MOUSE_R1_________________       Y_ZOOM,   Y_WARP_L,  Y_WARP_D,    Y_WARP_U,   Y_WARP_R
#define __________________MOUSE_R2_________________       Y_TOGGL,  Y_SPC_L,   Y_APPWIN,    Y_M_CTL,    Y_SPC_R
#define __________________MOUSE_R3_________________       Y_CENTRE, Y_WIN_L,   Y_WIN_D,     Y_WIN_U,    Y_WIN_R


#define __________________SYM_2_L1_________________       _______,  _______,    _______,    _______,     _______
#define __________________SYM_2_L2_________________       SECTION,  EURO,       POUND,      KC_PIPE,    DEGREE
#define __________________SYM_2_L3_________________       _______,  _______,    _______,    _______,    _______

#define __________________SYM_2_R1_________________       RGB_MOD,  RGB_VAI,    RGB_HUI,    RGB_SAI,    RGB_SPI
#define __________________SYM_2_R2_________________       RGB_TOG,  ________________CALLUM_MODS_R______________
#define __________________SYM_2_R3_________________       KC_NO,    KC_NO,      KC_CAPS,    JWE_PROJ,   KC_NO


#define ___________________FUNC_L1_________________       QK_BOOT,  EE_CLR,     KC_NO,      KC_NO,      QK_REBOOT
#define ___________________FUNC_L2_________________       ________________CALLUM_MODS_L______________,  SLEEP
#define ___________________FUNC_L3_________________       KC_LEFT,  KC_UP,      KC_DOWN,    KC_RIGHT,   KC_NO

#define ___________________FUNC_R1_________________       QK_REBOOT,KC_F7,      KC_F8,      KC_F9,      KC_F12
#define ___________________FUNC_R2_________________       SLEEP,    KC_F4,      KC_F5,      KC_F6,      KC_F11
#define ___________________FUNC_R3_________________       KC_NO,    KC_F1,      KC_F2,      KC_F3,      KC_F10


#define _ALPHAS_APTMAK \
    __________________APTMAK_L1________________, __________________APTMAK_R1________________, \
    __________________APTMAK_L2________________, __________________APTMAK_R2________________, \
    __________________APTMAK_L3________________, __________________APTMAK_R3________________

#define _ALPHAS_ENGRAM \
    __________________ENGRAM_L1________________, __________________ENGRAM_R1________________, \
    __________________ENGRAM_L2________________, __________________ENGRAM_R2________________, \
    __________________ENGRAM_L3________________, __________________ENGRAM_R3________________
#define _ALPHAS_QWERTY \
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, \
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, \
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
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
    QK_LEAD,  k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, KC_NO, \
    KC_NO,     k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, KC_NO, \
    KC_NO, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, KC_NO
#define LAYOUT_5x3_TO_6x3(...) _LAYOUT_5x3_TO_6x3(__VA_ARGS__)

#define _LAYOUT_ADD_THUMBS(...) __VA_ARGS__, ________________CALLUM_THUMBS______________
#define LAYOUT_ADD_THUMBS(...) _LAYOUT_ADD_THUMBS(__VA_ARGS__)

#define _LAYOUT_ADD_THeMBS(...) __VA_ARGS__, ________________aptmak_THUMBS______________
#define LAYOUT_ADD_THeMBS(...) _LAYOUT_ADD_THeMBS(__VA_ARGS__)

/* #define _LAYOUT_ADD_WYST_THeMBS(...) __VA_ARGS__, _________________wyst_THUMBS_______________ */
/* #define LAYOUT_ADD_WYST_THeMBS(...) _LAYOUT_ADD_WYST_THeMBS(__VA_ARGS__) */

#define _LAYOUT_WYST( \
  k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, \
  k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, \
  k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, \
                      k35, k36 \
    ) \
    k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, \
    __TL1__, __TR1__, __TL2__, k35, k36, __TR2__, KC_E, __TR3__
#define LAYOUT_WYST(...) _LAYOUT_wyst_custom(_LAYOUT_WYST(__VA_ARGS__))


#define _LAYOUT_ergodox_wrapper( \
    k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, \
                   k31, k32, k33, k34, k35, k36                 \
  ) \
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,        KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, \
      k01,    k11,  k03,  k04,  k05,  k06,  KC_NO,        KC_NO, k07,  k08,  k09,  k0A,  k1C,  k0C,     \
      k02,    k12,  k13,  k14,  k15,  k16,                       k17,  k18,  k19,  k1A,  k1B,  k0B,     \
      k21,    k22,  k23,  k24,  k25,  k26,  KC_NO,        KC_NO, k27,  k28,  k29,  k2A,  k2B,  k2C,     \
      KC_NUBS,  KC_NO,KC_NO,KC_NO,k31,                                   k36,  KC_NO,KC_NO,KC_NO,KC_NO,   \
                                      KC_NO,KC_NO,        KC_NO, KC_NO,                                 \
                                            KC_NO,        KC_NO,                                        \
                                k32,  k33,  KC_NO,        KC_NO, k34,  k35
#define LAYOUT_ergodox_wrapper(...) _LAYOUT_ergodox_wrapper(__VA_ARGS__)
