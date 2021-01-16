# Sam Townsend
# Makefile
# sft3hy
# 10/9/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=HashTable.o wordPuzzle.o timer.o 

WordPuzzle: HashTable.o wordPuzzle.o timer.o
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Word Puzzle compiled!"

HashTable.o: HashTable.cpp HashTable.h

wordPuzzle.o: wordPuzzle.cpp

timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o *.~ WordPuzzle
