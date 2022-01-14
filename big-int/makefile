UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC := g++
endif
ifeq ($(UNAME_S),Darwin)
	CC := clang++
endif
FLAGS := -std=c++17

.PHONY: all
all:

%.o: %.cc %.hh
	$(CC) $(FLAGS) -c $<
%.o: %.cc
	$(CC) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(PROGRAM)
	rm -f *.o
