

ROOT ?= ../..

EXTERNLIBS += \
	$(ROOT)/pukan/libpukan.a \
	
ASFLAGS += \
	-I$(ROOT)
	
LIBS += \
	-lglfw -lvulkan
	
