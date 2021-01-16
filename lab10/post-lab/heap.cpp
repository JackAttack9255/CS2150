// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heapVec.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffNode*> vec) : heap_size(vec.size()) {
    heapVec = vec;
    heapVec.push_back(heapVec[0]);
    heapVec[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

int heap::getSize() {
    return heapVec.size();
}

huffNode* heap::getNode(int x){
    return heapVec.at(x);
}



void heap::insert(huffNode* h) {
    // a vector push_back will resize as necessary
    heapVec.push_back(h);
    // move it up into the right position
    percolateUp(heap_size++);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffNode* x = heapVec[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < heapVec[hole/2]->freq); hole /= 2) {
        heapVec[hole] = heapVec[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heapVec[hole] = x;
}

huffNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffNode* ret = heapVec[1];
    // move the last inserted position into the root
    heapVec[1] = heapVec[heap_size--];
    // make sure the vector knows that there is one less element
    heapVec.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);

    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffNode* x = heapVec[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heapVec[child+1]->freq < heapVec[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > heapVec[child]->freq) {
            heapVec[hole] = heapVec[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heapVec[hole] = x;
}

int heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heapVec[1]->freq;
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapVec.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heapVec[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heapVec[i]->c << ": " << heapVec[i]->freq << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}