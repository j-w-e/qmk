#!/bin/zsh

# make sure you have "brew install qmk/qmk/qmk" first

KEYBOARD_HOME="$(pwd)"
export QMK_HOME="$KEYBOARD_HOME/qmk_firmware"
USER_SPACE="$QMK_HOME/users"
CRKBD="keyboards/crkbd/r2g/keymaps"
ERGODOX="keyboards/ergodox_ez/shine/keymaps"
LBS="keyboards/tweetydabird/lbs4/keymaps"

if [[ ! -d "$QMK_HOME" ]]
then
    echo "Add git sub-modules..."
    # git clone --depth 1 https://github.com/qmk/qmk_firmware
    git submodule add https://github.com/qmk/qmk_firmware.git 
    git submodule update --init --recursive 
fi

if [[ ! -d "$QMK_HOME/$CRKBD" ]]
then
    echo "adding r2g keymap directory"
    mkdir "$QMK_HOME/$CRKBD"
fi

if [[ ! -d "$QMK_HOME/$ERGODOX" ]]
then
    echo "adding ergodox keymap directory"
    mkdir "$QMK_HOME/$ERGODOX"
fi

# If manually simlinking, this will work
# but I have switched to doing it in the makefile
# if [[ ! -d "$USER_SPACE/_jwe_" ]]
# then
#     echo "Creating userspace symbolic link..."
#     ln -s "$KEYBOARD_HOME/user-config/_jwe_" "$USER_SPACE"
# fi
# if [[ ! -d "$QMK_HOME/$CRKBD/_jwe_" ]]
# then
#     rm -rf "$QMK_HOME/$CRKBD"
#     echo "Creating CRKBD symbolic link..."
#     ln -s "$KEYBOARD_HOME/user-config/$CRKBD" "$QMK_HOME/$CRKBD"
# fi
# if [[ ! -d "$QMK_HOME/$ERGODOX/_jwe_" ]]
# then
#     rm -rf "$QMK_HOME/$ERGODOX"
#     echo "Creating ERGODOX symbolic link..."
#     ln -s "$KEYBOARD_HOME/user-config/$ERGODOX" "$QMK_HOME/$ERGODOX"
# fi
# if [[ ! -d "$QMK_HOME/$LBS/jwe" ]]
# then
#     rm -rf "$QMK_HOME/$LBS"
#     echo "Creating LBS symbolic link..."
#     ln -s "$KEYBOARD_HOME/user-config/$LBS" "$QMK_HOME/$LBS"
# fi
#
qmk setup --yes
qmk config user.keyboard=crkbd/r2g
qmk config user.keymap=_jwe_
