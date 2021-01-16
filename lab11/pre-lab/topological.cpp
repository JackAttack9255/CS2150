#include "node.h"


#include <array>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <queue>

using namespace std;
/** Constructor
 * \brief structure that contains the node
 * struct to hold a node
 */

bool nodeCmp (node* i,node* j) { return (i->name < (j->name)); }


int NUM_VERTICES;

/** find
* \fn find
 *  \brief A member function.
 *  \param v vector of nodes
 *  \param name name of class to search for
 *  \return a node
*
*/
node* find(vector<node*> v, string name) {
	for(int i = 0; i < v.size(); i++) {
		if(v.at(i)->name == name) {
			return v.at(i);
		}
	}
	return NULL;
}

void printStructure(vector<node*> v) {
	cout<< "Structure" << endl;
	for(int i = 0; i < v.size(); i++) {
		cout << v.at(i)->name << " -> ";
		for(int j = 0; j < v.at(i)->pointingToVec.size(); j++) {
			cout << v.at(i)->pointingToVec.at(j)->name;
			if(j != v.at(i)->pointingToVec.size() - 1)
				cout << " -> ";
		}
		cout << endl;
	}
	
}

void printInDegree(vector<node*> v) {
	cout << "InDegree" << endl;
	for(int i = 0; i < v.size(); i++) {
		cout << v.at(i)->name << ": " << v.at(i)->indegree << endl;
	}
}

void printAdjacents(vector<node*> v) {
	cout << "Adjacents: " << endl;
	for(int i = 0; i < v.size(); i++) {
		cout << v.at(i)->name << ": ";
		for(int j = 0; j < v.at(i)->adjacentNodes.size(); j++) {
			cout << v.at(i)->adjacentNodes.at(j)->name;
			if(j != v.at(i)->adjacentNodes.size() - 1)
				cout << " - ";
		}
		cout << endl;
	}
	
}



int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Must supply the input file name as the one and only parameter" << endl;
		exit(1);
	}

    // attempt to open the supplied file
	ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
	if (!file.is_open()) {
		cout << "Unable to open file '" << argv[1] << "'." << endl;
		exit(2);
	}

	string line;

	vector<node*> nodeVec;

	while (getline(file, line)) {
		istringstream iss(line);
		if(line == "----------------------------------------"){
			break;
		}
		int mid = line.find(' ');

		if(line.substr(0, mid) == "0") {
			break;
		}

		string oneName = line.substr(0, mid);
		string twoName = line.substr(mid+1);



		//if neither are found, make new nodes and assign one to point to two and push both
		node* n1 = find(nodeVec, oneName);
		node* n2 = find(nodeVec, twoName);

		if(n1 == NULL && n2 == NULL) {
			node* classOne = new node();
			classOne->name = oneName;
			node* classTwo = new node();
			classTwo->name = twoName;

			classOne->pointingToVec.push_back(classTwo);

			classTwo->indegree++;

			nodeVec.push_back(classOne);
			nodeVec.push_back(classTwo);

			NUM_VERTICES += 2;

			classOne->adjacentNodes.push_back(classTwo);
			classTwo->adjacentNodes.push_back(classOne);
		}

		//if the first one is found but not the second one, make a new node for the second one and assign one to point to two and push the second one
		if(n1 != NULL && n2 == NULL) {
			node* classTwo = new node();
			classTwo->name = twoName;
			node* classOne = find(nodeVec, oneName);
			classOne->pointingToVec.push_back(classTwo);

			classTwo->indegree++;

			nodeVec.push_back(classTwo);

			NUM_VERTICES += 1;

			classOne->adjacentNodes.push_back(classTwo);
			classTwo->adjacentNodes.push_back(classOne);

		}

		//if the second one is but not the first one, make a new node for the first one and assign it to point to two and push the first one
		if(n1 == NULL && n2 != NULL) {
			node* classOne = new node();
			classOne->name = oneName;
			node* classTwo = find(nodeVec, twoName);
			classOne->pointingToVec.push_back(classTwo);

			classTwo->indegree++;

			nodeVec.push_back(classOne);

			NUM_VERTICES += 1;

			classOne->adjacentNodes.push_back(classTwo);
			classTwo->adjacentNodes.push_back(classOne);
		}


		//if both are already in the vector, just grab the first node from vector and point it at second
		if(n1 != NULL && n2 != NULL) {
			node* classOne = find(nodeVec, oneName);
			node* classTwo = find(nodeVec, twoName);

			classTwo->indegree++;

			classOne->pointingToVec.push_back(classTwo);

			classOne->adjacentNodes.push_back(classTwo);
			classTwo->adjacentNodes.push_back(classOne);
		}

	}



	sort(nodeVec.begin(), nodeVec.end(), nodeCmp);

	for(int i = 0; i < nodeVec.size(); i++) {
		sort(nodeVec.at(i)->adjacentNodes.begin(), nodeVec.at(i)->adjacentNodes.end(), nodeCmp);
		sort(nodeVec.at(i)->pointingToVec.begin(), nodeVec.at(i)->pointingToVec.end(), nodeCmp);
	//cout << nodeVec.at(i)->name << endl;
	}


	deque<node*> q;
	vector<node*> nVec;

	for(int i = 0; i < NUM_VERTICES; i++) {

		node* v = nodeVec.at(i);
		if(v->indegree == 0) {
			q.push_front(v);
		}
	}

	//dequeue and sort
	while (q.size() != 0) {	

		for(int i = 0; i < q.size(); i++) {
			nVec.push_back(q.front());
			q.pop_front();
		}
	}

	sort(nVec.begin(), nVec.end(), nodeCmp);
	for(int i = 0; i < nVec.size(); i++) {
		//cout << nVec.at(i)->name << " ";
	}
	//enqueue
	for(int i = 0; i < nVec.size(); i++) {
		q.push_front(nVec.at(i));
	}
	vector<node*> sortVec;
	while(q.size() != 0){
		node* v = q.front();
    	q.pop_front(); // get vertex of indegree 0
    	sortVec.push_back(v);
  		for(int j = 0; j < v->adjacentNodes.size(); j++) { // insert eligible verts
  			node* w = v->adjacentNodes.at(j);
  		if (--w->indegree == 0) {
  			sort(nodeVec.begin(), nodeVec.end(), nodeCmp);
  			q.push_front(w);
  		}
  	}
  }

  sort(sortVec.begin(), sortVec.end(), nodeCmp);

  sortVec.erase( unique( sortVec.begin(), sortVec.end() ), sortVec.end() );

  for(int i = 0; i < sortVec.size(); i++) {
  	cout << sortVec.at(i)->name << " ";
  }

cout << endl;

for(int i = 0; i < q.size(); i++) {
	q.pop_front();
}

for(int i = 0; i < sortVec.size(); i++) {
	delete sortVec.at(i);
}

file.clear(); // Clears the _state_ of the file, not its contents!
file.seekg(0);

}

