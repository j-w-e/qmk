#include "_jwe_.h"
#include "g/keymap_combo.h"

/* bool get_combo_must_tap(uint16_t index, combo_t *combo){ */
/*         // everything should be tap-only unless otherwise specified */
/*         return true; */
/* } */

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case comb_q:
        case comb_qu:
        case comb_z:
        case comb_x:
            return 50;
    }
    return COMBO_TERM;

}
