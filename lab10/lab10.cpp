/*
    lab10.cpp

    main() function for CSCI 262 Data Structures lab 10.
*/
#include <iostream>
#include "bit_counter.h"
#include "int_counter.h"
#include "mod_counter.h"
#include "bounded_counter.h"

using namespace std;

int main() {
   counter* counters[5];
   counters[0] = new bit_counter;
   counters[1] = new bit_counter(4);
   counters[2] = new int_counter;
   counters[3] = new mod_counter(7);
   counters[4] = new bounded_counter(10);

   string response;
   while (true) {
       for (int i = 0; i < 5; i++) {
           cout << counters[i]->to_string() << "  ";
           counters[i]->increment();
       }
	   cout << "Enter to continue, q to quit ";
	   getline(cin, response);
	   if (response == "q") break;
   }
}
