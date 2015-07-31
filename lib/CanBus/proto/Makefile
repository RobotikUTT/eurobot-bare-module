include ../../../NanoPb/extra/nanopb.mk

SOURCES = $(wildcard ./*.proto)
CFILES = $(SOURCES:.proto=.pb.c)
HFILES = $(SOURCES:.proto=.pb.h)


%.pb.c %.pb.h: %.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. $<

all: $(CFILES)

clean:
	rm -f $(CFILES) $(HFILES)


.PHONY: all clean
