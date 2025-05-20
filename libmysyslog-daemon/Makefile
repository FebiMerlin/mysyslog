CC=gcc
CFLAGS=-Wall -O2 -I../libmysyslog
LDFLAGS=

all: mysyslog-daemon.exe

mysyslog-daemon.exe: main.c ../libmysyslog/mysyslog.h ../libmysyslog/libmysyslog.a
	$(CC) $(CFLAGS) main.c -o mysyslog-daemon.exe ../libmysyslog/libmysyslog.a -lws2_32

clean:
	del /Q *.exe 2>NUL || true 