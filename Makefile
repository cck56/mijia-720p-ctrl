
LIB_PATH=/usr/src/arm-linux-3.3/toolchain_gnueabi-4.4.0_ARMv5TE/usr/lib
CROSS_COMPILE=/usr/src/arm-linux-3.3/toolchain_gnueabi-4.4.0_ARMv5TE/usr/bin/arm-linux-

CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AS=$(CROSS_COMPILE)as

PROGS=mijia_ctrl

LDFLAGS +=
CFLAGS += -Wall -O2

TARGETS := $(PROGS)

.PHONY: $(TARGETS)

all: $(TARGETS)

$(TARGETS): %: %.c
	LD_LIBRARY_PATH=$(LIB_PATH) $(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -f $(TARGETS)

