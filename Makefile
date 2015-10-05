# Redirect unmatched rules to src/main/Makefile
.DEFAULT_GOAL := .DEFAULT
.DEFAULT:
	$(MAKE) -C ./src/main/ $(MAKECMDGOALS)


clean:
	$(MAKE) -C ./src/main/ clean

.PHONY: clean




