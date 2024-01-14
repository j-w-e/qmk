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

bool override_shift(bool is_shifted,
    uint16_t shift_override,
    uint16_t keycode,
    keyrecord_t *record);
void check_rgb_timeout(void);
void refresh_rgb(void);
bool check_if_oled_should_be_on(void);

#endif
