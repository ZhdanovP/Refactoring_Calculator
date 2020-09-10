CXX = c++
# CXX = g++
# CXX = clang++

CXXFLAGS += -Wall
CXXFLAGS += -std=c++17
CXXFLAGS += -O2
# CPPFLAGS += -g3 -DDEBUG

PROG = test
OBJ = monopoly.o

all: $(PROG) $(OBJ)

clean:
	rm -f *.o $(PROG)

run: test
	./test

.PHONY: all clean run
