
#include <iostream>

#include "huffNode.h"
#include <string>

using namespace std;

huffNode::huffNode() {
  leftChild = NULL;
  rightChild = NULL;
  c = (char) 0;
  freq = 1;
  code = "";
}
huffNode::huffNode(char character, int frequency)
{
  leftChild = NULL;
  rightChild = NULL;
  c = character;
  freq = frequency;
  code = "";
}




