/*
	postfix_calculator.h

	Header file for the postfix calculator.  

    CSCI 262, Spring 2018, Project 2

	author: Carter Fowler
*/

#ifndef _POSTFIX_CALCULATOR_H
#define _POSTFIX_CALCULATOR_H

#include <string>
#include <stack>
#include <set>

/*
    TODO:  You will need to
	add some member variables to store the state of your
	calculator; you may also add any methods you need.  Keep
	in mind that whatever changes you make, your code should
	still work with calculator_main.cpp.
*/

class postfix_calculator {
public:
	// Take in and process a string query such as "7 14 * 3 /".
	// The string is read left to right.  Numbers are pushed onto
	// the stack.  All other strings are assumed to be operators.
	// If the operator is a binary operator such as "+", then two
	// numbers are popped off the stack, the binary operator is
	// applied, and the answer is pushed back on the stack.  If
	// the operator is a unary operator such as "sin" (if 
	// implemented), then only one number is popped off and the
	// answer pushed.
    // 
    // Note that some expressions might leave extra numbers on
    // the stack - e.g., "1 2 3 +" should result in the stack
    // containing the values "1 5".  A subsequent user entry of
    // "*" would then be valid, for instance. 
	//
	// IF the query causes a stack underflow situation (i.e., 
	// an operator requires an operand but the stack is empty),
	// then the method should return false, and the stack should
    // be emptied.
	bool evaluate(std::string);

	// Remove all items from the current stack.
	void clear();

	// Return the number at the top of the stack (this will be the
	// answer if a valid query was passed to evaluate).  If the
	// stack is empty, returns 0.0.  The number  should *not* be 
	// popped from the stack (this allows further  calculations
	// using this number).
	double top();

	// Return a string representation of the stack showing all the
	// elements in it.  Hint: make a copy of the stack to display
    // the contents of.
	std::string to_string();

	// Constructor
	postfix_calculator();


private:
	// TODO: declare member variables here for your stack, etc.
	std::stack<std::string> memory;
	std::set<std::string> double_operators = {"*", "/", "+", "-", "^", "hyp"};
	std::set<std::string> single_operators = {"sqrt", "log", "ln", "sin", "cos", "tan", "csc", "sec", "cot", "dsin", "dcos", "dtan", "dcsc", "dsec", "dcot", "asin", "acos", "atan", "acsc", "asec", "acot", "to_deg", "base-e", "cbrt"};
	double degree_converter = (3.14159265 / 180);
};

#endif
