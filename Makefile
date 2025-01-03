# NOTE TODO I have not added my charybdis yet to this workflow
# Currently, it needs the following command run in qmk folder
	# make bastardkb/charybdis/4x6/v2/splinky_3:_jwe_:flash
#
#
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
	# cd qmk_firmware
	# git pull
	# cd ..

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
	# cd qmk_firmware
	# git pull
	# cd ..

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

.PHONY: ck_flash
ck_flash: crkbd
	cd qmk_firmware; qmk flash ../crkbd_r2g__jwe_.hex

.PHONY: eez_flash
eez_flash: ergodox_ez
	cd qmk_firmware; qmk flash --mcu atmega32u4 ../ergodox_ez_shine__jwe_.hex

.PHONY: wysteria
wysteria:
	# cd qmk_firmware
	# git pull
	# cd ..

# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/$@
	rm -rf qmk_firmware/users/$(USER)

# add new symlinks
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$@
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)

# run lint check
	# cd qmk_firmware; qmk lint -km $(USER) -kb $@ --strict

# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $@:_jwe_

# cleanup symlinks
	rm -rf qmk_firmware/keyboards/$@


.PHONY: flash_wyst
flash_wyst: wysteria
	cp ./wysteria__jwe_.uf2 /Volumes/RPI-RP2/wyst.uf2


clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -f *.tmp
	rm -f *.uf2
