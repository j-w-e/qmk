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

VPATH  +=  keyboards/gboards/
COMBO_ENABLE = yes

ifeq ($(strip $(USERSPACE_LEADER)), yes)
    OPT_DEFS += -DUSERSPACE_LEADER
		SRC += leader.c
endif

ifeq ($(strip $(USERSPACE_CAPS_WORD)), yes)
    OPT_DEFS += -DUSERSPACE_CAPS_WORD
		SRC += casemodes.c
endif

ifeq ($(strip $(LUNA_ENABLE)), yes)
    OPT_DEFS += -DLUNA_ENABLE
	WPM_ENABLE = yes
endif

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
	  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
	    OPT_DEFS += -DNO_SECRETS
endif
