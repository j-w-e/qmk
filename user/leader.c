#include QMK_KEYBOARD_H
#include "defines.h"
#include "secrets.h"

#ifdef LEADER_ENABLE
void leader_end_user(void) {

    if (leader_sequence_one_key(KC_H)) {
        SEND_STRING("Hugh");
    } else if (leader_sequence_two_keys(KC_L, KC_E)) {
        layer_move(ENGRAM);
    } else if (leader_sequence_two_keys(KC_L, KC_A)) {
        layer_move(APTMAK);
    } else if (leader_sequence_two_keys(KC_L, KC_N)) {
        layer_move(NAV);
    } else if (leader_sequence_two_keys(KC_G, KC_G)) {
        layer_on(MOUSE);
        layer_on(NUM);
#ifndef NO_SECRETS
        // secrets file contains:
        // 0 is segregation
        // 1 is email
        // 2 is phone number
        // 3 is OH's email
        // 4 is OH's phone number
        // 5 is work email
    } else if (leader_sequence_two_keys(KC_S, KC_E)) {
        send_secret(0);
    } else if (leader_sequence_two_keys(KC_S, KC_G)) {
        send_secret(1);
    } else if (leader_sequence_two_keys(KC_S, KC_P)) {
        send_secret(2);
    } else if (leader_sequence_two_keys(KC_S, KC_J)) {
        send_secret(3);
    } else if (leader_sequence_two_keys(KC_S, KC_K)) {
        send_secret(4);
    } else if (leader_sequence_two_keys(KC_S, KC_N)) {
        send_secret(5);
#endif
    /* } else if (leader_sequence_one_key(KC_X)) { */
    /*     enable_xcase_with(KC_UNDS); */
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        SEND_STRING(SS_LSFT(SS_LCMD("5")));
    } else if (leader_sequence_two_keys(KC_W, KC_B)) {
        SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL(SS_LALT("b")))));
    } else if (leader_sequence_two_keys(KC_W, KC_R)) {
        SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL(SS_LALT("r")))));
    } 

}

#endif // LEADER_ENABLE
