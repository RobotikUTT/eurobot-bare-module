include ../../pb/extra/nanopb.mk

PROTOC_OPTS += -I=./ -I=../ -I=../../pb/generator/proto/

SOURCES = $(wildcard ./*.proto)
CFILES = $(SOURCES:.proto=.pb.c)
HFILES = $(SOURCES:.proto=.pb.h)

all: $(CFILES)

clean:
	rm -f $(CFILES) $(HFILES)


.PHONY: all clean
