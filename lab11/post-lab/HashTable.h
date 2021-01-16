/*
 * Sam Townsend
 * sft3hy
 * 9/8/2020
 * HashTable.h
 */

#ifndef HASH_TABLE
#define HASH_TABLE

#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class HashTable {
 public:
  
  void insert(string s);
  bool find(string s);

  HashTable();

  
  vector<list<string>> t;
  int hash(string s);
};

#endif
