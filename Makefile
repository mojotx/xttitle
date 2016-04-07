
#CC=gcc
CC=clang
CFLAGS=-Os -Wall -Wextra -pedantic -fstack-protector -fstack-protector-all -pipe
RM=rm -rvf


xttitle: src/xttitle.c
	$(CC) -o $@ $<

clean:
	$(RM) xttitle core


