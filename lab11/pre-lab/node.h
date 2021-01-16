#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class node {
public:
	node();
	node(string name);
	string name;
	vector<node*> pointingToVec;
	int indegree;
	vector<node*> adjacentNodes;

};

#endif