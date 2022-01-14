OUT := base-convert
OBJS := main.o big-int/ap_n.o

CXX := g++
CXXFLAGS := -std=c++17

TMP := .$(OUT)

$(OUT): $(OBJS)
	touch $(TMP).cc
	make $(TMP)
	mv $(TMP) $@
	rm $(TMP)*

$(TMP): $(TMP).cc $(OBJS)

big-int/%.o:
	make -C big-int $(@:big-int/%=%)

.PHONY: clean
clean:
	make -C big-int clean
	rm -f *.o
	rm -f $(OUT)
	rm -f $(TMP)*
