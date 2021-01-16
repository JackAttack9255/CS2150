/*
 * Sam Townsend
 * sft3hy
 * 9/8/2020
 * hashTable.cpp
 */

#include "HashTable.h"
#include <vector>
#include <iterator>

using namespace std;

HashTable::HashTable() {
  t = vector<list<string>>(50000);
}

int HashTable::hash(string s) {
  int hash = 0;
  int i = 0;
  int vSize = t.size();
  for(int j = 0; j < s.length(); j++) {
    hash += (int)s[j];
  }
  i = hash%vSize;
  return i;
}


void HashTable::insert(string s) {
  t[hash(s)].push_front(s);
}


bool HashTable::find(string s) {
  int ind = hash(s);
  list<string>::iterator it;
  for(it = t[ind].begin(); it != t[ind].end(); it++) {
    if((*it).compare(s) == 0) {
      return true;
    }
  }
  return false;
}
