# Sam Townsend
# Makefile
# sft3hy
# 11/2/2020

CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=linkedlist.o

linkedlist: linkedlist.o 
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Linked List compiled!"

linkedlist.o: linkedlist.c 

.PHONY: clean
clean:
	-rm -f *.o *.~ linkedlist
