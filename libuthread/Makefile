# Target library
lib := libuthread.a

all: $(lib)

## TODO: Phase 1 and Phase 2

CFLAGS	:= -Wall -Werror
# CFLAGS	+= -pipe

## Debug flag
ifneq ($(D),1)
CFLAGS	+= -O2
else
CFLAGS	+= -O0
CFLAGS	+= -g
endif

# Don't print the commands unless explicitely requested with `make V=1`
ifneq ($(V),1)
Q = @
V = 0
endif

# Define compilation toolchain
CC	= gcc

all: $(lib)

$(lib): queue.o thread.o sem.o
	$(Q)ar rcs $(lib) $^

sem.o: sem.c sem.h
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

#tps.o: tps.c tps.h
#	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

# %.o: %.c %.h
# 	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

#Don't remove queue.o or thread.o
clean:
	$(Q)rm -f sem.o
	$(Q)rm -f tps.o
	$(Q)rm libuthread.a