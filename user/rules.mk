SRC += _jwe_.c

SRC += oneshot.c
SRC += swapper.c


LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
TAP_DANCE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
EXTRAKEY_ENABLE = yes
REPEAT_KEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
LEADER_ENABLE = yes

VPATH  +=  keyboards/gboards/
COMBO_ENABLE = yes
INTROSPECTION_KEYMAP_C = combos.c

ifeq ($(strip $(USERSPACE_CAPS_WORD)), yes)
    OPT_DEFS += -DUSERSPACE_CAPS_WORD
		SRC += casemodes.c
endif

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
	  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
	    OPT_DEFS += -DNO_SECRETS
endif
