// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef USERSPACE
#define USERSPACE

#pragma once

#include QMK_KEYBOARD_H
#include "defines.h"

// Features
#include "oneshot.h"
#include "swapper.h"

#ifndef NO_SECRETS
#include "secrets.h"
#endif

#ifdef SPLIT_KEYBOARD
#   define MASTER_LEFT
#endif


enum userspace_layers {
    ENGRAM = 0,
    APTMAK,
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

bool override_shift(bool is_shifted,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record);

#endif
