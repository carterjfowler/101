/*
    CSCI 262 Data Structures, Project 4 - Markov

    map_model.h

    Class declaration for map based markov_model (abstract base class for Markov model
    classes).

    Author: Carter Fowler

    Modified: 3/19/18
*/

#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include "model.h"
#include <map>
#include <vector>

using namespace std;

class map_model : public markov_model {
public:
	// give the model the example text and the model order; the model
	// should do any preprocessing in this call
	virtual void initialize(std::string text, int order);

	// produce a text in the style of the example
	virtual std::string generate(int size);

protected:
	std::string _data;
	map <string, vector<char>> k_grams;
	int _order;
};

#endif