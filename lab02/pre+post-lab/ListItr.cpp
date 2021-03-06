/*
 *Sam Townsend
 *9/13/2020
 *sft3hy
 *ListItr.cpp
 */

#include "ListItr.h"
#include "List.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

ListItr::ListItr() {
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const{
  if(current->next == NULL){
    return true;
  } return false;
}

bool ListItr::isPastBeginning() const{
 if(current->previous == NULL){
    return true;
  } return false;
}

void ListItr::moveForward(){
  if(current->next != NULL){
    current = current->next;
  }
}

void ListItr::moveBackward(){
  if(current->previous != NULL){
    current = current->previous;
  }
}

int ListItr::retrieve()const{
  return current->value;
}
