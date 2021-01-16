/*
 *Sam Townsend
 *9/22/2020
 *sft3hy
 *stack.h
 */

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

class Stack {
  
 public:
  Stack();

  void push(int x);

  void pop();

  int top();

  bool empty();

  int size;
 private:
  List l;

  friend class postfixCalculator;

};

#endif
