// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffNode*> vec) : heap_size(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    heap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffNode* h) {
    // a vector push_back will resize as necessary
    heap.push_back(h);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffNode* x = heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < heap[hole/2]->freq); hole /= 2) {
        heap[hole] = heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

huffNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffNode* ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffNode* x = heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heap[child+1]->freq < heap[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > heap[child]->freq) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

int heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heap[1]->freq;
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heap[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap[i]->c << ": " << heap[i]->freq << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}