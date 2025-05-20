SUBDIRS = libmysyslog libmysyslog-text libmysyslog-json libmysyslog-client libmysyslog-daemon

all:
	@for d in $(SUBDIRS); do \
		$(MAKE) -C $$d || exit 1; \
	done

clean:
	@for d in $(SUBDIRS); do \
		$(MAKE) -C $$d clean; \
	done

.PHONY: all clean 