
#CC=gcc
CC=clang
CFLAGS+=-Os -Wall -Wextra -pedantic -fstack-protector -pipe
RM=rm -vf

all: xttitle

xttitle: src/xttitle.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	$(RM) xttitle core


