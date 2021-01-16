# Sam Townsend
# Makefile
# sft3hy
# 11/17/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS= solver.o HashTable.o

puzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen


solver.o: solver.cpp

HashTable.o: HashTable.cpp HashTable.h

.PHONY: clean
clean:
	-rm -f *.o *.~ puzzle
