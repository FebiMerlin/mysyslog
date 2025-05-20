CC=gcc
CFLAGS=-Wall -O2 -I.
AR=ar
ARFLAGS=rcs

all: libmysyslog.a

libmysyslog.o: mysyslog.c mysyslog.h
	$(CC) $(CFLAGS) -c mysyslog.c -o libmysyslog.o

libmysyslog.a: libmysyslog.o
	$(AR) $(ARFLAGS) $@ $^

clean:
	del /Q *.o *.a 2>NUL || true 