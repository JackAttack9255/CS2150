#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "huffNode.h"
#include <string>
#include <map>

class huffmanTree {
public:
	huffmanTree();
	huffmanTree(huffNode* n);
	~huffmanTree();
	int weight;
	void printCode(huffNode* root, string s);

	huffNode* root;
	map<char, string> codeMap;
};


#endif