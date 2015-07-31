.DEFAULT_GOAL := .DEFAULT
.DEFAULT:
	$(MAKE) -C ./src/main/ $(MAKECMDGOALS)

proto:
	$(MAKE) -C ./lib/BusCan/proto/ all

clean:
	$(MAKE) -C ./lib/BusCan/proto/ clean
	$(MAKE) -C ./src/main/ clean

.PHONY: proto clean
