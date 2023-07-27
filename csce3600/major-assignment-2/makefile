SOURCEDIR = src
INCLUDEDIR = include

SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
HEADERS := $(shell find $(INCLUDEDIR) -name '*.h')

CFLAGS = -I$(INCLUDEDIR) -Wall

newshell: $(SOURCES)
	gcc $(CFLAGS) -o $@ $^
