# JWE's keymap

This is a custom, mostly 36-key keymap specifically for me. With a few extra optional side-keys, such as a zoom-mute button.

This repo is designed so that I can work independently of the qmk repo. There is an init script that clones qmk, and sym-links the 'user-config' sub-folders into the relevant places in the qmk_firmware clone.

It draws on a range of code from multiple users, that I have shamelessly just copied and modified to suit my own purposes.

1. Case modes from here: https://github.com/andrewjrae/kyria-keymap#case-modes
2. Callum mods from here: https://github.com/qmk/qmk_firmware/tree/master/users/callum (though I have adapted the one-shot shift so that the first tap enables shift, and then the second tap enables caps word). Have also added the ctrl-gui swap function, depending if you're in windows or mac mode.
3. Callum swapper, for cmd-tab and alt-tab, but with the added function of being able to use shift to cycle backwards through windows
4. Implementation of secrets from drashna, but modified to allow the secret strings to be called from leader sequences, rather than keycodes

I've tried to code it so that a wide range of functions can be enabled or disabled in rules.mk, to account for what space is available on the mcu. 

1. Multiple macros are OS-dependent. Defining `BOTH` adds the option to switch between the OS versions of those macros. Defining `WINDOWS` or `MAC` (the default) just allows for ctrl-gui swap, but the macros don't adjust.
2. A userspace function for leader key, and the built-in leader. Both work. I can't remember why I enabled both. Pick one.
3. A userspace function for caps word, and the built-in caps_word. If there's space, use the userspace one, and add x-case too. 


I'll try to write this all up in a better manner.
