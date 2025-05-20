CC=gcc
CFLAGS=-Wall -O2 -I.
LDFLAGS=-shared

all: mysyslog_json.dll

mysyslog_json.o: mysyslog_json.c mysyslog_json.h
	$(CC) $(CFLAGS) -c mysyslog_json.c -o mysyslog_json.o

mysyslog_json.dll: mysyslog_json.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	del /Q *.o *.dll 2>NUL || true 