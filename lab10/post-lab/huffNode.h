#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class huffNode {
 public:

  huffNode();
  huffNode(char character, int frequency);
  
  huffNode* leftChild;
  huffNode* rightChild;


  char c;
  int freq;
  string code;
  friend class heap;
};
#endif
