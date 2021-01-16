#include <iostream>
#include <vector>
#include <map>
#include "huffmanTree.h"
#include "huffNode.h"

huffmanTree::huffmanTree() {
	//huffNode* root = NULL;
}

huffmanTree::huffmanTree(huffNode* n) {
	root = n;
}

huffmanTree::~huffmanTree(){
}


void huffmanTree::printCode(huffNode* n, string s){
	bool space = isspace(n->c);
	if(n->c != (char) 0) {
		n->code = s;
		codeMap.insert(pair<char,string>(n->c,n->code));
		if(space) {
			cout << "space" << " " << n->code << endl;
		} else {
		cout << n->c << " " << n->code << endl;
		}
	} else {
		if(n->leftChild) {
			s+= "0";
			printCode(n->leftChild, s);
			s.pop_back();
		}
		if(n->rightChild) {
			s+= "1";
			n->rightChild->code = s;
			printCode(n->rightChild, s);
			s.pop_back();
		}
	}
}



