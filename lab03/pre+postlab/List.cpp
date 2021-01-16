/*
 *Sam Townsend
 *9/15/2020
 *sft3hy
 *List.cpp
 */

#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->previous = NULL;
  tail->next = NULL;
  head->next=tail;
  tail->previous=head;
  count = 0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::~List(){
  if(!this->isEmpty()) {
    this->makeEmpty();
  }
  head->next = NULL;
  tail->previous = NULL;
  delete head;
  delete tail;
}

bool List::isEmpty() const {
  if(head->next == tail && tail->previous == head) {
    return true;
  } return false;
}

void List::makeEmpty() {
  if(!this->isEmpty()) {
    ListItr emptier = head->next;
    for(int i = 0; i < count; i++) {
      ListNode* curr = emptier.current;
      emptier.moveForward();
      curr->previous = NULL;
      curr->next = NULL;
      delete curr;
    }
    head->next=tail;
    tail->previous=head;
    count = 0;
  }
}

ListItr List::first() {
  ListItr itr = ListItr(head);
  itr.moveForward();
  return itr;
}

ListItr List::last() {
  ListItr itr = ListItr(tail);
  itr.moveBackward();
  return itr;
}

void List::insertAfter(int x, ListItr position) {
  count += 1;
  ListNode* nodeToInsert = new ListNode();
  nodeToInsert->value = x;
  nodeToInsert->previous = position.current;
  nodeToInsert->next = position.current->next;
  position.current->next->previous=nodeToInsert;
  position.current->next=nodeToInsert;
}

void List::insertBefore(int x, ListItr position) {
  count += 1;
  ListNode* nodeToInsert = new ListNode();
  nodeToInsert->value = x;
  nodeToInsert->next = position.current;
  nodeToInsert->previous = position.current->previous;
  position.current->previous->next = nodeToInsert;
  position.current->previous = nodeToInsert;
}

void List::insertAtTail(int x) {
  ListItr nodeToInsertBeforeTail = ListItr(tail);
  insertBefore(x, nodeToInsertBeforeTail);
}

ListItr List::find(int x) {
  ListItr itr = ListItr(head);
  while(!itr.isPastEnd()) {
    if(itr.current->value == x) {
      return itr;
    }
    itr.moveForward();
  }
  ListItr xNotFound = ListItr(tail);
  return xNotFound;
}
 

void List::remove(int x) {
    ListItr itr = ListItr(head->next);
    while(!itr.isPastEnd()) {
      if(itr.current->value == x) {
	itr.current->previous->next = itr.current->next;
	itr.current->next->previous = itr.current->previous;
	itr.current->next = NULL;
	itr.current->previous = NULL;
	delete itr.current;
	count--;
	break;
      }
      itr.moveForward();
    }
}

void List::removeLast() {
  ListItr itr = ListItr(tail->previous);
  itr.current->previous->next = tail;
  tail->previous = itr.current->previous;
  itr.current->next = NULL;
  itr.current->previous = NULL;
  delete itr.current;
  count--;
}


int List::size() const{
  return count;
}

void printList(List& source, bool forward) {
  if(forward) {
    ListItr forwardItr = source.first();
    string forwardStringToAppendTo = "";
    while(!forwardItr.isPastEnd()) {
      string element = to_string(forwardItr.retrieve());
      forwardStringToAppendTo += element;
      forwardStringToAppendTo += " ";
      forwardItr.moveForward();
    }
    cout << forwardStringToAppendTo;
  } else {
    ListItr backwardItr = source.last();
    string backwardStringToAppendTo = "";
    while(!backwardItr.isPastBeginning()) {
      string element = to_string(backwardItr.retrieve());
      backwardStringToAppendTo += element;
      backwardStringToAppendTo += " ";
      backwardItr.moveBackward();
    }
    cout << backwardStringToAppendTo;
  }
}
