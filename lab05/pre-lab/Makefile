# Sam Townsend
# sft3hy
# Makefile
# 09/4/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=TreeCalc.o TreeCalcTest.o TreeNode.o

exprTree: TreeCalc.o TreeCalcTest.o TreeNode.o
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Expression Tree Compiled!"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h


.PHONY: clean
clean:
	-rm -f *.o *.~ exprTree
