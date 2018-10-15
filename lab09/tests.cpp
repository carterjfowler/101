/*
    tests.cpp

    Tests for the Queue class. 

    Code for CSCI 262 lab 3 - Queues

    Author: C. Painter-Wakefield
*/

#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

int NUM_PASSED = 0;

void test_true(bool expr, string desc);

/* 
   NOTE: Make sure your ARRAY_SZ constant in Queue.h is set such that your
   Queue has a capacity of exactly 5 elements.
*/

int main() {
    Queue<char> my_queue;
    cout << "Phase 1 Tests: " << endl;
    //Phase 1 tests
    my_queue.enqueue('a');
    test_true(!my_queue.is_empty(), "Queue isn't empty.");
    test_true(my_queue.front() == 'a', "'a' was the first element in the queue.");
    my_queue.enqueue('g');
    my_queue.enqueue('d');
    my_queue.dequeue();
    test_true(my_queue.front() == 'g', "'g' was the first element in the queue.");
    my_queue.enqueue('e');
    my_queue.enqueue('y');
    my_queue.enqueue('l');
    my_queue.dequeue();
    my_queue.dequeue();
    my_queue.dequeue();
    my_queue.dequeue();
    test_true(my_queue.front() == 'l', "'l' was the first element in the queue.");
    
    // single element tests
    // test_true(q.enqueue('x'), "Queue reports true on successful enqueueing.");
    // test_true(!q.is_empty(), "Queue is not empty after enqueueing.");
    // test_true(q.front() == 'x', "Queue front element is the element enqueued.");
    // test_true(q.dequeue(), "Queue reports true on successful dequeuing.");
    // test_true(q.is_empty(), "Queue is empty after dequeuing single element.");

    //Phase 2: Big 3 tests
    cout << endl << "Phase 2 Tests: " << endl;
    Queue<char> new_queue;
    new_queue.enqueue('a');
    
    
    Queue<char> test_queue;
    test_queue = new_queue;
    test_true(!test_queue.is_empty(), "Queue isn't empty.");
    test_true(test_queue.front() == 'a', "'a' was the first element in the queue using assignment");
    
    Queue<char> other_test_queue(new_queue);
    test_true(other_test_queue.front() == 'a', "'a' was the first element in the queue using copy");
    
    //Phase 3: template tests
    cout << endl << "Phase 3 Tests: " << endl;
    Queue<int> my_int_queue;
    
    my_int_queue.enqueue(1);
    test_true(!my_int_queue.is_empty(), "Queue isn't empty.");
    test_true(my_int_queue.front() == 1, "'1' was the first element in the queue.");
    my_int_queue.enqueue(3);
    my_int_queue.enqueue(8);
    my_int_queue.dequeue();
    test_true(my_int_queue.front() == 3, "'3' was the first element in the queue.");
    my_int_queue.enqueue(5);
    my_int_queue.enqueue(9);
    my_int_queue.enqueue(2);
    my_int_queue.dequeue();
    my_int_queue.dequeue();
    my_int_queue.dequeue();
    my_int_queue.dequeue();
    test_true(my_int_queue.front() == 2, "'2' was the first element in the queue.");
    

    Queue<int> new_int_queue;
    new_int_queue.enqueue(2);
    new_int_queue.enqueue(5);
    new_int_queue.enqueue(8);
    new_int_queue.enqueue(12);
    new_int_queue.enqueue(34);
    
    cout << endl << "Phase 2 Tests Pt. 2: " << endl;
    
    Queue<int> test_int_queue;
    test_int_queue = new_int_queue;
    test_true(!test_int_queue.is_empty(), "Queue isn't empty.");
    test_true(test_int_queue.front() == 2, "'2' was the first element in the queue using assignment");
    
    Queue<int> other_test_int_queue(new_int_queue);
    test_true(test_int_queue.front() == 2, "'2' was the first element in the queue using copy");

    return 0;
}

void test_true(bool expr, string desc) {
    if (!expr) {
        cerr << "FAILED test: ";
    } else {
        cerr << "Passed test: ";
        NUM_PASSED++;
    }
    cerr << '"' << desc << '"' << endl;
}

