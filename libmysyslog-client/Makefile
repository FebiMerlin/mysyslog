CC=gcc
CFLAGS=-Wall -O2 -I../libmysyslog
LDFLAGS=

all: mysyslog-client.exe

mysyslog-client.exe: main.c ../libmysyslog/mysyslog.h ../libmysyslog/libmysyslog.a
	$(CC) $(CFLAGS) main.c -o mysyslog-client.exe ../libmysyslog/libmysyslog.a

clean:
	del /Q *.exe 2>NUL || true 