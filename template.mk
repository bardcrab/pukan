

STATICLIB = lib$(PROGRAM).a
EXECUTABLE = $(PROGRAM)

CC = gcc
XX = g++
LD = g++
RM = rm -f
AR = ar rcs

ASFLAGS = -c -MD -march=native \
	-fno-diagnostics-show-option \
	-fno-diagnostics-show-caret \
	-finput-charset=UTF-8
	
CCFLAGS = $(ASFLAGS) \
	-O2 -Wall
	
XXFLAGS = $(ASFLAGS) \
	-O2 -Wall -std=gnu++17 \
	-exceptions -pthread
	
LDFLAGS = \
	-shared-libgcc -pthread

rwildcard = $(wildcard $1$2) \
	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
	
OBJS = \
	$(patsubst %.c,%.o,$(call rwildcard,./,*.c)) \
	$(patsubst %.cpp,%.o,$(call rwildcard,./,*.cpp))
	
LIBS ?=
EXTERNLIBS ?=

CONFIG = ../config.mk
include $(CONFIG)

DEPS = $(call rwildcard,./,*.d)


default:
	@echo no target specified
	
executable: $(EXECUTABLE)
	
staticlib: $(STATICLIB)
	
$(STATICLIB): $(OBJS)
	@echo $@
	@$(AR) $(STATICLIB) $(OBJS)
	
$(EXECUTABLE): $(CONFIG) $(OBJS) $(EXTERNLIBS)
	@echo $@
	@$(LD) $(LDFLAGS) $(OBJS) $(EXTERNLIBS) $(LIBS) -o $(EXECUTABLE)
	
%.o: %.cpp $(CONFIG)
	@echo $@
	@$(XX) $(XXFLAGS) $< -o $@

%.o: %.c $(CONFIG)
	@echo $@
	@$(CC) $(CCFLAGS) $< -o $@

clean:
	@echo $@
	@$(RM) $(OBJS) $(DEPS) $(STATICLIB) $(EXECUTABLE)
	

ifneq ($(MAKECMDGOALS),clean)
include $(DEPS)
endif

