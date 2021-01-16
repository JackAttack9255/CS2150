#include "board.h"
#include "HashTable.h"
#include <list>
#include <iterator>


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#include <tuple>
#include <functional>
using namespace std;


vector<string> generateNeighbors(string b);

vector<int> generateCanSwapWithIndexes(string b, int tmpIndex);

int main() {

	//handle input
	vector<int> v;
	string firstThree;
	string secondThree;
	string thirdThree;
	cout << "Enter puzzle" << endl;
	getline (cin, firstThree);
	getline (cin, secondThree);
	getline (cin, thirdThree);

	string input = firstThree + secondThree + thirdThree;
	input.erase(remove(input.begin(), input.end(), '\n'), input.end());
	input.erase(remove(input.begin(), input.end(), ' '), input.end());

	int inversions = 0;
	for(int i = 0; i < 9; i++) {
		for(int j = i+1; j < 9; j++) {
			if(input[i] > input[j] && input[i] != '0' && input[j] != '0') {
				inversions++;
			}
		}
	}


	cout << "Solving puzzle" << endl;

	if(inversions % 2 != 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	
	HashTable h = HashTable();
	h.insert(input);

	if(input == "123456780") {
		cout << "0" << endl;
		return 0;
	}
	//generateNeighbors(startBoard);

	queue<string> q;
	map<string, int> m;
	bool complete = false;

	int solutionSteps = 0;
	q.push(input);
	m[input] = 0;
	while(!complete){
		string b = q.front();
		q.pop(); // get vertex of indegree 0
		vector<string> nabes = generateNeighbors(b);
		if(b == "123456780") {
  			complete = true;
  			solutionSteps = m[b];
  			cout <<  solutionSteps << endl;

  			return 0;
  		}
  		for(int j = 0; j < nabes.size(); j++) { // insert eligible verts

  			string w = nabes[j];
  			if(m.count(w) == 0) {
  				m[w] = m[b] + 1;
  				h.insert(w);
  				q.push(w);
  			} else {
  				continue;
  			}
  			
  		}
  	}



  //cout << *min_element(solutionSteps.begin(), solutionSteps.end()) << endl;

  	for(int i = 0; i < q.size(); i++) {
  		q.pop();
  	}


  	return 0;

  }

//
  vector<string> generateNeighbors(string bo) {
  	int tmpIndex2 = bo.find("0");
  	vector<int> cswi = generateCanSwapWithIndexes(bo, tmpIndex2);
  	vector<string> returnVec;
  	for(int i = 0; i < cswi.size(); i++) {
  		string onePossibility = bo;
  		int tmpIndex1 = cswi.at(i);
  		int temporaryVal = onePossibility[tmpIndex2];
  		onePossibility[tmpIndex2] = onePossibility[tmpIndex1];
  		onePossibility[tmpIndex1] = temporaryVal;



  		returnVec.push_back(onePossibility);

  	}
  	return returnVec;
  }

/** \brief generates indexes that 0 can swap around with
* @param b - string board
* @param tmpIndex - index to 
* \fn generateCanSwapWithIndexes
* @return a vector of ints that indicates where 0 can go
*/ 
  vector<int> generateCanSwapWithIndexes(string b, int tmpIndex) {
	vector<int> v;
	if(tmpIndex == 0) {
		v = {1, 3};
		return v;
	}
	if(tmpIndex == 1) {
		v = {0, 2, 4};
		return v;
	}
	if(tmpIndex == 2) {
		v = {1, 5};
		return v;
	}
	if(tmpIndex == 3) {
		v = {0, 4, 6};
		return v;
	}
	if(tmpIndex == 4) {
		v = {1, 3, 5, 7};
		return v;
	}
	if(tmpIndex == 5) {
		v = {2, 4, 8};
		return v;
	}
	if(tmpIndex == 6) {
		v = {3, 7};
		return v;
	}
	if(tmpIndex == 7) {
		v = {4, 6, 8};
		return v;
	}
	if(tmpIndex == 8) {
		v = {5, 7};
		return v;
	}
	v = {};
	return v;
}













