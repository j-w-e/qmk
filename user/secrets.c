#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
static const char * const secrets[] = {
  "test0"
  "test1",
  "test2",
  "test3",
  "test4",
  "test5"
};
#endif

#include QMK_KEYBOARD_H

void send_secret(uint8_t secret) {
// Secrets!  Externally defined strings, not stored in repo
        clear_mods();
        send_string_with_delay(secrets[secret], 5);
}
