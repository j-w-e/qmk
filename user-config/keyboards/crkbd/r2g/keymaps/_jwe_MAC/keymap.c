#include "_jwe_.h"
#include "defines.h"

#define _LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_jwe_wrapper(...) _LAYOUT_wrapper(LAYOUT_ADD_THUMBS(LAYOUT_5x3_TO_6x3(__VA_ARGS__)))

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CLMK] = LAYOUT_jwe_wrapper(_ALPHAS_COLEMAK),
#ifdef QWERTY
    [QWER] = LAYOUT_jwe_wrapper(_ALPHAS_QWERTY),
#endif

    [SYM] = LAYOUT_jwe_wrapper(_ALPHAS_SYMBOLS),
    [NAV] = LAYOUT_jwe_wrapper(_ALPHAS_NAV),
    [NUM] = LAYOUT_jwe_wrapper(_ALPHAS_NUMBERS),
  	[MOUSE] = LAYOUT_jwe_wrapper(_ALPHAS_MOUSE),
  	[SYM2] = LAYOUT_jwe_wrapper(_ALPHAS_SYM2),
  	[FUNC] = LAYOUT_jwe_wrapper(_ALPHAS_FUNC),

};
