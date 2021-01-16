# Sam Townsend
# Makefile
# sft3hy
# 11/5/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=heap.o huffmandec.o huffNode.o huffmanTree.o

Huffman: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "huffmandec compiled!"

heap: heap.cpp heap.h

huffmandec.o: huffmandec.cpp

huffNode.o: huffNode.cpp huffNode.h

huffmanTree.o: huffmanTree.cpp huffmanTree.h

.PHONY: clean
clean:
	-rm -f *.o *.~ Huffman
