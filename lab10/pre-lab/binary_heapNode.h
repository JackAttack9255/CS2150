#ifndef BINARY_HEAPNODE_H
#define BINARY_HEAPNODE_H

#include <iostream>
#include <vector>
using namespace std;

class huffNode {
 public:
  huffNode();
  huffNode(char character, int frequency);
  
  huffNode *leftChild;
  huffNode *rightChild;
  
  char c;
  int freq;
  
  friend class binary_heap;
};
#endif
