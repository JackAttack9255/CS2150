/* Sam Townsend
 * sft3hy
 * huffmanenc.cpp
 * 11/7/2020
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


  //inspiration from https://stackoverflow.com/questions/7241871/loading-a-file-into-a-vectorchar from here:
  ostringstream oss;
  oss << file.rdbuf();
  string s = oss.str();
  // to here

  vector<char> accepted;
  for(int i = 32; i < 127; i++) {
    accepted.push_back(i);
  }
  

  for(int i = 0; i < 31; i++){
    s.erase(remove(s.begin(), s.end(), i),s.end());
  }

  s.erase(remove(s.begin(), s.end(), 127),s.end());
  

  map<char, int> m;

  for(int i = 0; i < s.length(); i++) {
    if(m.cend() == m.find(s[i])) {
      m.insert(make_pair(s[i], 1));
    } else {
      m[s[i]]++;
    }
  }

  vector<pair<char, int> > v; 

  // Copy key-value pair from Map 
  // to vector of pairs 
  for (auto& it : m) { 
    v.push_back(it); 
  }

        // Sort using comparator function 
  sort(v.begin(), v.end(), cmp);

  vector<char> chars;
  vector<int> freqs;


  for (auto& it : v) { 
    chars.push_back(it.first);
    freqs.push_back(it.second);
  } 


  heap heep;
  vector<huffNode*> nodesVec;

  for(int i = 0; i < chars.size(); i++) {
    huffNode* tmp = new huffNode(chars[i], freqs[i]);
    heep.insert(tmp);
    nodesVec.push_back(tmp);
  }



  bool flip = false;
  while(heep.getSize() > 2) {
    huffNode* delOne = heep.deleteMin();

    huffNode* delTwo = heep.deleteMin();

    huffNode* parent = new huffNode();

    parent->freq = delOne->freq + delTwo->freq;
    parent->c = (char) 0;

    if(flip){
      parent->leftChild = delTwo;
      parent->rightChild = delOne;
    } else {
      parent->leftChild = delOne;
      parent->rightChild = delTwo;
    }
    if(flip == 0){
      flip = 1;
    } else {
      flip = 0;
    }
    heep.insert(parent);
  }

huffNode* top = heep.getNode(1);

huffmanTree h = huffmanTree(top);

h.printCode(top, "");
cout << "----------------------------------------" << endl;

for(int i = 0; i < s.size(); i++){
  cout << h.codeMap[s[i]] << " ";
}

  float cost = 0;
  for(int i = 0; i < nodesVec.size(); i++){
    cost += costCalc(nodesVec.at(i));
  }
  float compressed = cost;
  cost /= (float) s.size();

cout << endl;
cout << "----------------------------------------" << endl;

cout << "There are a total of " << s.size()<< " symbols that are encoded." << endl;

cout << "There are " <<v.size() << " distinct symbols used." << endl;

cout <<"There were " << s.size()*8<< " bits in the original file." << endl;

cout <<"There were " << compressed << " bits in the compressed file." << endl;

cout << "This gives a compression ratio of "  << (s.size()*8)/compressed << endl;


cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;




  
  file.clear(); // Clears the _state_ of the file, not its contents!
  file.seekg(0);

  
  return 0;
}
