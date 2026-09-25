# Root Makefile - builds all targets and installs myutils
SUBDIRS = src

all: build install

build:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d; done

install: build
	@cp bin/client /usr/bin/client
	@chmod a+x /usr/bin/client
	@chmod og-w /usr/bin/client
	@cp man/man3/client.1 /usr/local/share/man/man1/client.1
	@cp man/man3/libmyutils.3 /usr/local/share/man/man3/libmyutils.3
	@echo "myutils successfully installed in /usr/bin"

uninstall:
	@rm -f /usr/bin/client
	@rm -f /usr/local/share/man/man1/client.1
	@rm -f /usr/local/share/man/man3/libmyutils.3
	@echo "myutils successfully un-installed"

clean:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done

.PHONY: all build clean install uninstall