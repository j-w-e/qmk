# JWE's keymap

This is JWE's custom QMK keymap. Primarily for the custom [Wysteria](https://github.com/j-w-e/wysteria/). ZMK version, which is nearly identical but does not have OLED animations or underglow, [is also available](https://github.com/j-w-e/zmk-config). I have older versions for my Ergodox EZ and Corne R2G, but I no longer use them so they may be out of date.

## Mini write-up

This is a custom, mostly 42-key keymap specifically for me. Makes use of a corresponding skhd setup, for many of the longer macro commands for [yabai](https://github.com/koekeishiya/yabai) for example.

The Makefile symlinks the relevant folders into the QMK tree, compiles, and then removes itself. It relies on the qmk_firmware folder being a subfolder of this, `.gitignore`d by this repo. I'll try to change that, when the This is a [QMK external userspace](https://docs.qmk.fm/#/newbs_external_userspace), with an added few commands run prior to compile. This adds symliks into the main qmk repo to allow for the custom keyboard definition for my wysteria.

It draws on a range of code from multiple users, that I have shamelessly just copied and modified to suit my own purposes.

1. Callum mods from here: https://github.com/qmk/qmk_firmware/tree/master/users/callum (though I have adapted the one-shot shift so that the first tap enables shift, and then the second tap enables caps word). Have also added the ctrl-gui swap function, depending if you're in windows or mac mode.
2. Callum swapper, for cmd-tab and alt-tab, but with the added function of being able to use shift to cycle backwards through windows
3. Implementation of secrets from drashna, but modified to allow the secret strings to be called from leader sequences, rather than keycodes
