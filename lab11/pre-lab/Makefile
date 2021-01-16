# Sam Townsend
# Makefile
# sft3hy
# 11/12/2020

CXX=clang++ -std=c++11 $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=middleearth.o topological.o node.o

top: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen

middleearth.o: middleearth.cpp middleearth.h

topological.o: topological.cpp

node.o: node.cpp node.h

.PHONY: clean
clean:
	-rm -f *.o *.~ top
