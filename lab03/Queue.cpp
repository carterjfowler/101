/*
    Queue.cpp
        
    Method implementations for Queue class

    assignment: CSCI 262 Lab 3 - Queues        

    author: 

    last modified: 9/7/2017
*/

/* 
   NOTE: if you prefer, the Queue class is simple enough that you can do all
   of your methods inline. However, you need to keep this file, or else
   modify the Makefile so that the compile will not fail.

   NOTE that inline means that all of your method definitions can be in the
   header, rather than in this separate .cpp file; inline does not mean all 
   of your code should be on one line!
*/
#include "Queue.h"

using namespace std;

bool Queue::enqueue(char c) {
    if (_size > (ARRAY_SZ - 1)%ARRAY_SZ) {
        return false;
    } else {
        _data[_back] = c;
        ++_back;
        _back = _back%ARRAY_SZ;
        ++_size;
        return true;
    }
}

bool Queue::dequeue() {
    if(is_empty()) {
        return false;
    } else {
        ++_front;
        _front = _front%ARRAY_SZ;
        --_size;
        return true;
    }
}

char Queue::front() {
    return _data[_front];
}

bool Queue::is_empty() {
    if (_size == 0) {
        return true;
    } else {
        return false;
    }
}