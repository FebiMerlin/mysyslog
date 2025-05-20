CC=gcc
CFLAGS=-Wall -O2 -I.
LDFLAGS=-shared

all: mysyslog_text.dll

mysyslog_text.o: mysyslog_text.c mysyslog_text.h
	$(CC) $(CFLAGS) -c mysyslog_text.c -o mysyslog_text.o

mysyslog_text.dll: mysyslog_text.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	del /Q *.o *.dll 2>NUL || true 