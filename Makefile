# this method comes from https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd
# usage: make all, or make lbs, or make crkbd, or make ergodox_ez
USER = _jwe_

KEYBOARDS = crkbd ergodox_ez
PATH_crkbd = r2g
PATH_ergodox_ez = shine
PATH_lbs = tweetydabird/lbs4

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	# git submodule update --init --recursive
	cd qmk_firmware
	git pull
	cd ..

# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$@/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

# add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$@/keymaps/$(USER)

# run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $@/$(PATH_$@) --strict

# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $@/$(PATH_$@):$(USER)

# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$@/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

.PHONY: lbs
lbs:
	# init submodule
	git submodule update --init --recursive

# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

# add new symlinks
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

# run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(PATH_$@) --strict

# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $(PATH_$@):$(USER)

# cleanup symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

.PHONY: flash
flash: crkbd
	cd qmk_firmware; qmk flash ../crkbd_r2g__jwe_.hex

# .PHONY: flash_ez
# flash: ergodox_ez
# 	cd qmk_firmware; qmk flash ../ergodox_ez_shine__jwe_.hex

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
