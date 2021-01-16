/* Sam Townsend
 * sft3hy
 * huffmandec.cpp
 * 11/9/2020
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "heap.h"
#include "huffNode.h"
#include "huffmanTree.h"

// file I/O
#include <fstream>
#include <sstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include <algorithm>

using namespace std;



// Comparator function to sort pairs in a map
// according to second value 
bool cmp(pair<char, int>& a, pair<char, int>& b) { 
	return a.second < b.second; 
}

float costCalc(huffNode* n) {
	return (float)(n->freq)*(n->code.length());
}


int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Must supply the input file name as the one and only parameter" << endl;
		exit(1);
	}


	ifstream file(argv[1]);
  // if the file wasn't found, output an error message and exit
	if (!file.is_open()) {
		cout << "Unable to open '" << argv[1] << "' for reading" << endl;
		exit(2);
	}


	vector<string> chars;
	vector<string> codeVec;
	string g;
	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		if(line == "----------------------------------------"){
			break;
		}
		int mid = line.find(' ');
		if(line.substr(0, mid) == "space") {
			chars.push_back(" ");
		} else {
			chars.push_back(line.substr(0, mid));
		}
		codeVec.push_back(line.substr(mid+1));
	}
file.clear(); // Clears the _state_ of the file, not its contents!
file.seekg(0);
//chars and codeVec are now vectors in order that contain the letters and codes, respectively


  //inspiration from https://stackoverflow.com/questions/7241871/loading-a-file-into-a-vectorchar from here:
ostringstream oss;
oss << file.rdbuf();
string s = oss.str();
  // to here
string wholeFile = s;

int begin = 0;
int end = 0;



begin = s.find("-\n") + 2;
s = s.substr(begin);

end = s.find("\n-");

s = s.substr(0, end);


vector<string> codedLetters;
string tmp;

for(int i = 0; i < s.size()+1; i++){
	if(s[i] == ' ' || s[i] == '\n') {
		codedLetters.push_back(tmp);
		tmp = "";
	} else {
		tmp += s[i];
	}
}

vector<char> cars;
for(int i = 0; i < chars.size(); i++) {
	if(chars.at(i) == " ") {
		cars.push_back(' ');
	} else {
		string tmp = chars.at(i);
		char tmpy = tmp[0];
		cars.push_back(tmpy);
	}
}



  //codedLetters is now a vector of each individual encoded character in the encoded message, including spaces

  //use chars, codeVec, and codedLetters

//to do: have parent be the root node and have anything done by tmpParent reflect in parent
huffNode* parent = new huffNode();
for(int i = 0; i < chars.size(); i++) {
	huffNode* tmpParent = parent;
	huffNode* realNode = new huffNode();
	int k = 0;
	string cvai = codeVec.at(i);

	realNode->c = cars.at(i);

  	//inner for loop: iterates through the prefix code and finds the correct spot for a node
	for(int j = 0; j < cvai.length(); j++) {
		char cvaij = cvai[j];

		if(cvaij == '0') {
			if(tmpParent->leftChild == NULL){
				huffNode* tmp = new huffNode();
				tmpParent->leftChild = tmp;
			}
			tmpParent = tmpParent->leftChild; 
		} else if(cvaij == '1') {
			if(tmpParent->rightChild == NULL) {
				huffNode* tmp = new huffNode();
				tmpParent->rightChild = tmp;
			}
			tmpParent = tmpParent->rightChild;
		}
		k++;
	}
	char cvaik = cvai[k-1];

	//if previous value of j (k) is 1, insert at right, else insert at left
	if(cvaik == '1'){
		tmpParent->rightChild = realNode;
	} else if(cvaik == '0') {
		tmpParent->leftChild = realNode;
	}
}

huffmanTree h = huffmanTree(parent);



for(int i = 0; i < codedLetters.size(); i++) {
	int k = 0;
	huffNode* itr = parent;
	string individualCode = codedLetters.at(i);
	for(int j = 0; j < individualCode.length(); j++) {
		if(individualCode[j] == '0') {
			itr = itr->leftChild;
		} else if(individualCode[j] == '1') {
			itr = itr->rightChild;
		}
		k++;
	}
	if(individualCode[k-1] == '0') {
		cout << itr->leftChild->c;
	} else if(individualCode[k-1] == '1') {
		cout << itr->rightChild->c;
	}
}
cout << endl;




}








