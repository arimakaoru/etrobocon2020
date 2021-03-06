mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
    Controller.o \
    Display.o \
    EtRobocon2020.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += \
    $(mkfile_path)app \
    $(mkfile_path)module \
    $(mkfile_path)module/api \

INCLUDES += \
    -I$(mkfile_path)app \
    -I$(mkfile_path)module \
    -I$(mkfile_path)module/api \

COPTS += -std=gnu++11
