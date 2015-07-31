.DEFAULT_GOAL := .DEFAULT
.DEFAULT:
	$(MAKE) -C ./src/main/ $(MAKECMDGOALS)

proto:
	$(MAKE) -C ./lib/CanBus/proto/ all

clean:
	$(MAKE) -C ./lib/CanBus/proto/ clean
	$(MAKE) -C ./src/main/ clean

.PHONY: proto clean
