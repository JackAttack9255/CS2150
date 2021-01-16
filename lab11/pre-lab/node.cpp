#include "node.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


node::node() {
	name = "";
	indegree = 0;
}

node::node(string n) {
	name = n;
	indegree = 0;
}
