# This Makefile adds the right wysteria keyboard files to the main QMK folder
# Because external userspace does not currently allow building of out-of-tree
# keyboards.
#
# `make` works, and cleans up after itself in the main QMK_FIRMWARE_ROOT directory
# but doesn't currently leave the build filse available, for some reason
# 
# TODO add in the ability to call make and have it flash the keyboard 
# automatically
.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

FILES := $(shell find $(QMK_USERSPACE)/keyboards/wysteria -type f -maxdepth 1)

.PHONY: all wysteria_prep compile wysteria_clean

all: wysteria_prep compile wysteria_clean

wysteria_prep:
	echo "prepping"
	mkdir -p $(QMK_FIRMWARE_ROOT)/keyboards/wysteria
	for file in $(FILES); do \
		cp "$$file" $(QMK_FIRMWARE_ROOT)/keyboards/wysteria; \
	done

compile:
	echo "compiling"
	qmk userspace-compile

wysteria_clean:
	echo "cleaning"
	rm -rf $(QMK_FIRMWARE_ROOT)/keyboards/wysteria


clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -f *.tmp
	rm -f *.uf2


# %:
# 	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
