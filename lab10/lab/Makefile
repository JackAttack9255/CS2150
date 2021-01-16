# Sam Townsend
# Makefile
# sft3hy
# 11/5/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTSONE=heap.o huffmanenc.o huffNode.o huffmanTree.o
OBJECTSTWO=heap.o huffmandec.o huffNode.o huffmanTree.o


all: encoder decoder

encoder: $(OBJECTSONE)
	$(CXX) $(DEBUG) -o encoder $(OBJECTSONE)

decoder: $(OBJECTSTWO)
	$(CXX) $(DEBUG) -o decoder $(OBJECTSTWO)

heap.o: heap.cpp heap.h

huffmandec.o: huffmandec.cpp

huffNode.o: huffNode.cpp huffNode.h

huffmanTree.o: huffmanTree.cpp huffmanTree.h

.PHONY: clean
clean:
	-rm -f *.o *.~ encoder decoder
