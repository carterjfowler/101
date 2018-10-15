/*
	postfix_calculator.cpp

	Implementation of the postfix calculator. 

    CSCI 262, Spring 2018, Project 2

	author: Carter Fowler
*/

#include "postfix_calculator.h"
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;

postfix_calculator::postfix_calculator() {
	//constructor, nothing to declare
}

bool postfix_calculator::evaluate(string expr) {
	// TODO: Implement as per postfix_calculator.h
	//
	// Read the comments in postfix_calculator.h for this
	// method first!  That is your guide to the required
	// functioning of this method.
	//
	// There are various ways to parse expr.  I suggest
	// you create an istringstream object, constructed on
	// expr:
	// 	istringstream string_in(expr);
	// Then you can get each substring from expr using >>.
    //
    // Check each substring first to see if you have one of 
    // the four operators; if not, you can assume the value
    // is a number that you can convert to a double.  (This
    // may not be a good assumption - but we won't test you
    // on robustly handling anything other than numbers and
    // operators.)  You can use the stod() function in the
    // string library to convert strings to doubles.
    
    //populate stack and compute things as we go
    istringstream input(expr);
    double answer = 0.0;
    while(!input.eof()) {
    	string test;
    	input >> test;
    	if(double_operators.count(test) != 0 && memory.size() >= 2) {
    		double second_num = stod(memory.top());
    		memory.pop();
    		double first_num = stod(memory.top());
    		memory.pop();
	    	if (test == "*") {
	    		answer = first_num * second_num;
	    		memory.emplace(std::to_string(answer));
	    	} else if(test == "/") {
	    		answer = first_num / second_num;
	    		memory.emplace(std::to_string(answer));
	    	} else if(test == "+") {
	    		answer = first_num + second_num;
	    		memory.emplace(std::to_string(answer));
	    	} else if(test == "-") {
	    		answer = first_num - second_num;
	    		memory.emplace(std::to_string(answer));
	    	}
	    	//a number to the power of another number
	    	else if(test == "^") {
	    		answer = pow(first_num, second_num);
	    		memory.emplace(std::to_string(answer));
	    	}
			//find hypotenuse
	    	else if(test == "hyp") {
	    		answer = hypot(first_num, second_num);
	    		memory.emplace(std::to_string(answer));
	    	}
    	} else if (single_operators.count(test) != 0 && memory.size() >=1) {
    		double number = stod(memory.top());
    		memory.pop();
    		if(test == "sqrt") {
    			answer = sqrt(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "log") {
    			answer = log10(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "ln") {
    			answer = log(number);
    			memory.emplace(std::to_string(answer));
    		} 
    		//start of trig fxns, regular ones take in radians
    		else if(test == "sin") {
    			answer = sin(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "cos") {
    			answer = cos(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "tan") {
    			answer = tan(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "csc") {
    			answer = 1 / (sin(number));
    			memory.emplace(std::to_string(answer));
    		} else if(test == "sec") {
    			answer = 1 / (cos(number));
    			memory.emplace(std::to_string(answer));
    		} else if(test == "cot") {
    			answer = 1 / (tan(number));
    			memory.emplace(std::to_string(answer));
    		} 
    		//these take in degrees
    		else if(test == "dsin") {
    			answer = sin(number * degree_converter);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "dcos") {
    			answer = cos(number * degree_converter);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "dtan") {
    			answer = tan(number * degree_converter);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "dcsc") {
    			answer = 1 / (sin(number * degree_converter));
    			memory.emplace(std::to_string(answer));
    		} else if(test == "dsec") {
    			answer = 1 / (cos(number * degree_converter));
    			memory.emplace(std::to_string(answer));
    		} else if(test == "dcot") {
    			answer = 1 / (tan(number * degree_converter));
    			memory.emplace(std::to_string(answer));
    		}
    		//these are inverse ones, returns radians
    		else if(test == "asin") {
    			answer = asin(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "acos") {
    			answer = acos(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "atan") {
    			answer = atan(number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "acsc") {
    			answer = asin(1/number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "asec") {
    			answer = acos(1/number);
    			memory.emplace(std::to_string(answer));
    		} else if(test == "acot") {
    			answer = (3.14159265 / 2) - atan(number);
    			memory.emplace(std::to_string(answer));
    		}
    		//use this if you want to convert radians to degrees
    		else if(test == "to_deg") {
	    		answer = number * (1 / degree_converter);
	    		memory.emplace(std::to_string(answer));
	    	}
	    	//e to the power of inputed number
	    	else if(test == "base-e") {
	    		answer = exp(number);
	    		memory.emplace(std::to_string(answer));
	    	}
	    	//cube root
	    	else if(test == "cbrt") {
	    		answer = cbrt(number);
	    		memory.emplace(std::to_string(answer));
	    	}
    	} else if ((double_operators.count(test) != 0 && memory.size() < 2) || (single_operators.count(test) != 0 && memory.empty())) {
    		return false;
    	} else {
    		//if not any of the operators then must be a number so put in stack
    		memory.emplace(test);
    	}
    }
    return true;
}


// TODO: Implement the remaining functions specified
// in postfix_calculator.h.
//
// You should start by creating "stubs" for each of
// the methods - these are methods that do nothing
// except return a value if needed.  For example, the 
// evaluate() method above does nothing but return true.
//
// Once you've got stubs for everything, then you should
// be able to compile and test the user interface.  Then
// start implementing functions, *testing constantly*

void postfix_calculator::clear() {
	//empty the memory stack
	while(!memory.empty()) {
		memory.pop();
	}
}

double postfix_calculator::top() {
	//return the top of the stack, if empty return 0.0
	if(memory.empty()) {
		return 0.0;
	} else {
		double result = stod(memory.top());
		return result;
	}
}

string postfix_calculator::to_string() {
	//convert stack to string
	stack<string> copy = memory;
	string result;
	while(!copy.empty()) {
		result += copy.top();
		copy.pop();
	}
	return result;
}