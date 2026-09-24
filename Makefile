SUBDIRS = src

all:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d; done

clean:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done

PREFIX = /usr/local

install: all
	install -d $(PREFIX)/bin
	install -m 755 bin/client $(PREFIX)/bin/client
	install -d $(PREFIX)/share/man/man1
	install -m 644 man/man3/client.1 $(PREFIX)/share/man/man1/client.1
	install -d $(PREFIX)/share/man/man3
	install -m 644 man/man3/libmyutils.3 $(PREFIX)/share/man/man3/libmyutils.3


.PHONY: all clean install