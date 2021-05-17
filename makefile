OUT := base-convert
OBJS := main.o ap_n.o

CXX := g++
CXXFLAGS := -std=c++17

TMP := .$(OUT)

$(OUT): $(OBJS)
	touch $(TMP).cc
	make $(TMP)
	mv $(TMP) $@
	rm $(TMP)*

$(TMP): $(TMP).cc $(OBJS)

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(OUT)
	rm -f $(TMP)*
