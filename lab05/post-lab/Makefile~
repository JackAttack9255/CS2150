# Sam Townsend
# Makefile
# sft3hy
# 9/4/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=AVLNode.o AVLPathTest.o AVLTree.o

AVLTree: AVLNode.o AVLPathTest.o AVLTree.o
	$(CXX) $(DEBUG) $(OBJECTS) -o AVLTree
	@echo "AVLTree compiled!"

AVLNode.o: AVLNode.cpp

AVLPathTest.o: AVLPathTest.cpp

AVLTree.o: AVLTree.cpp

.PHONY: clean
clean:
	-rm -f *.o *.~ AVLTree
