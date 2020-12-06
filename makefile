

PARTS := \
	pukan \
	samples \
	

default: build
	
%:
	@for part in $(PARTS); do \
		$(MAKE) -C $$part $@; \
	done
	










