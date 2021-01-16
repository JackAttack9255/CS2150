/*
 *Sam Townsend
 *9/22/2020
 *sft3hy
 *stack.cpp
 */

#include <iostream>
#include <string>
#include "Stack.h"
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

Stack::Stack() {
  l = List();
  size = 0;
}

void Stack::push(int x) {
  l.insertAtTail(x);
  size += 1;
}


void Stack::pop() {
  l.removeLast();
  size -= 1;
}


int Stack::top() {
  return l.last().retrieve();
}

bool Stack::empty() {
  if(l.isEmpty()){
    return true;
  } return false;
}

