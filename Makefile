CC ?= cc
CFLAGS ?= -march=native -O2 -pipe

CFLAGS := $(CFLAGS) -Wall -Wextra -Werror

OBJS := src/main.o

.PHONY: build clean

build: gen-color-rect

clean:
	rm -f $(OBJS) gen-color-rect

gen-color-rect: $(OBJS)
	$(CC) $(CFLAGS) -Xlinker --strip-all -o $@ -lm $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
