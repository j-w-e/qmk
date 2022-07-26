#ifndef USERSPACE
#define USERSPACE

#pragma once


#include QMK_KEYBOARD_H
#include "version.h"

#include "quantum.h"
#include "keymap_uk.h"
#include "oneshot.h"
#include "swapper.h"
#include "defines.h"


#ifdef SPLIT_KEYBOARD
#   define MASTER_LEFT
#endif

extern bool WHICH_OS; // Switch between Mac and Win layouts. Mac is 0, Win is 1

enum userspace_layers {
    CLMK = 0,
#ifdef QWERTY
    QWER,
#endif
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

#ifndef LEADER_ENABLE
#ifndef USERSPACE_LEADER
    JWE_PWD,
#endif
#endif

    JWE_PROJ,
    JWE_MNE,
    JWE_NRC,
    JWE_TOGG,
#ifdef USERSPACE_LEADER
    JWE_LEAD,
#endif

    JWE_SHFT,
#ifdef MAC
    SLEEP,
#endif // MAC
    JWE_LINK,
#ifdef BOTH // need to enum the custom keycodes, if switching between mac and windows. otherwise, defines work
    SK_UNDO,
    SK_CUT,
    SK_COPY,
    SK_PSTE,
    SK_REDO,
    SK_HASH, //(which is KC_BSLASH on win, and RALT(KC_3) on mac
    SK_AT,
    SK_EURO,
    SK_WORDPRV, // WORD LEFT
    SK_WORDNXT, // WORD RIGHT
    SK_DOCEND, // Go to end of document
    SK_DOCBEG, // Go to start of document
    SK_LINEBEG, // Go to beg of line
    SK_LINEEND, // Go to end of line
    SK_PARAPRV, // Go to previous paragraph
    SK_PARANXT, // Go to next paragraph
    SK_WORDDEL,
    SK_WORDBSPC,
        //Might possibly need to add pipe and tilde
    SLEEP,
    JWE_DONE,
#endif // BOTH
};

#endif
