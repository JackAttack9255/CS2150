# Sam Townsend
# Makefile
# sft3hy
# 11/12/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=middleearth.o traveling.o

traveling: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen

middleearth.o: middleearth.cpp middleearth.h

traveling.o: traveling.cpp

.PHONY: clean
clean:
	-rm -f *.o *.~ traveling
