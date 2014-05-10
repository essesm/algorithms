DIRS = mergesort

all: $(DIRS)
	for dir in $(DIRS); do make -C $$dir; done;

clean: $(DIRS)
	for dir in $(DIRS); do make clean -C $$dir; done;
