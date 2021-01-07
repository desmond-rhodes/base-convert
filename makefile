CC := g++
FLAGS := -std=c++17
PROGRAM := program

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): main.o
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CC) $(FLAGS) -c $<
%.o: %.cc
	$(CC) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(PROGRAM)
	rm -f *.o
