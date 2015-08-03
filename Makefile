include ./lib/pb/extra/nanopb.mk

PROTOC_OPTS += -I=./common/pb/ -I=./lib/pb/generator/proto/
PROTOPATHS = $(wildcard common/pb/*.proto)
PROTOFILES = $(notdir $(PROTOPATHS))
OUTPUTFILES = $(addprefix lib/CanBus/,$(PROTOFILES))
CFILES = $(OUTPUTFILES:.proto=.pb.c)
HFILES = $(OUTPUTFILES:.proto=.pb.h)

proto: $(CFILES) $(HFILES)

lib/CanBus/%.pb.c lib/CanBus/%.pb.h: common/pb/%.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=./lib/CanBus/ $<

clean-proto:
	rm -f $(wildcard lib/CanBus/*.pb.c) $(wildcard lib/CanBus/*.pb.h)

# Redirect unmatched rules to src/main/Makefile
.DEFAULT_GOAL := .DEFAULT
.DEFAULT:
	$(MAKE) -C ./src/main/ $(MAKECMDGOALS)


clean: clean-proto
	$(MAKE) -C ./src/main/ clean

.PHONY: clean-proto proto clean




