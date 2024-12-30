// Copyright 2021 j-w-e
// SPDX-License-Identifier: GPL-2.0-or-later

/* taken from @callum-oakley with tweak from @daliusd */

#include "oneshot.h"
#include "defines.h"

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        /* case OS_SYM: */ // removing this from One-shot cancel because then I can just hold shift down and move between layers
        case LA_NAV:
        case LA_MOUSE:
        case LA_NUM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SYM:
        case LA_NAV:
        case LA_MOUSE:
        case LA_NUM:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NAV:
            if(layer_state_is(SYM)) {
                return false;
            }
        case OS_SYM:
        case LA_MOUSE:
        case LA_NUM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    switch (keycode) {
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
            if (!is_oneshot_ignored_key(keycode)) {
              switch (*state) {
              case os_up_queued:
                  *state = os_up_queued_used;
                  break;
              case os_up_queued_used:
                  *state = os_up_unqueued;
                  unregister_code(mod);
                  break;
              default:
                  break;
              }
          }

        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                case os_up_queued_used:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

bool update_oneshot_layer(
    oneshot_state *state,
    uint16_t layer,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record,
    uint16_t *sym_timer
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                layer_on(layer);
            }
            *state = os_down_unused;
            *sym_timer = timer_read();
            return false;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                if ( timer_elapsed(*sym_timer) > ONESHOT_TIMEOUT ) {
                  *state = os_up_unqueued;
                  *sym_timer = ONESHOT_TIMEOUT + 1;
                  layer_off(layer);
                  return false;
                }
                // If we didn't use the layer while trigger was held, queue it.
                *state = os_up_queued;
                return false;
            case os_down_used:
                // If we did use the layer while trigger was held, turn off it.
                *state = os_up_unqueued;
                *sym_timer = ONESHOT_TIMEOUT + 1;
                layer_off(layer);
                return false;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_layer_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot layer on designated cancel keydown.
                *state = os_up_unqueued;
                layer_off(layer);
                return false;
            }
            uint8_t key_layer = read_source_layers_cache(record->event.key);
            if (key_layer == layer) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    return true;
                case os_up_queued:
                    if (is_oneshot_mod_key(keycode)) {
                        *state = os_up_unqueued;
                        layer_off(layer);
                        return false;
                    } else {
                        *state = os_up_queued_used;
                    }
                    return true;
               case os_up_queued_used:
                    *state = os_up_unqueued;
                    layer_off(layer);
                    return false;
                default:
                    break;
                }
            }
        } else {
            // Ignore key ups from other layers
            uint8_t key_layer = read_source_layers_cache(record->event.key);
            if (key_layer == layer) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_up_queued:
                    *state = os_up_unqueued;
                    layer_off(layer);
                    return true;
                case os_up_queued_used:
                    *state = os_up_unqueued;
                    layer_off(layer);
                    return true;
                default:
                    break;
                }
            }
        }
    }
    return true;
}
