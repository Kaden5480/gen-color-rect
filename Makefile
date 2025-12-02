CC ?= cc
CFLAGS ?= -march=native -O2 -pipe

CFLAGS := $(CFLAGS) -Wall -Wextra -Werror

OBJS := src/main.o \
		src/cmd.o \
		src/lib/convert.o \
		src/lib/formats.o

.PHONY: build clean

build: gen-color-rect

clean:
	rm -f $(OBJS) gen-color-rect

gen-color-rect: $(OBJS)
	$(CC) $(CFLAGS) -Xlinker --strip-all -o $@ -lm $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
