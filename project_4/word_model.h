/*
    CSCI 262 Data Structures, Project 4 - Markov

    map_model.h

    Class declaration for map based markov_model (abstract base class for Markov model
    classes).

    Author: Carter Fowler

    Modified: 3/19/18
*/

#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include "model.h"
#include <map>
#include <vector>

using namespace std;

class word_model : public markov_model {
public:
	// give the model the example text and the model order; the model
	// should do any preprocessing in this call
	virtual void initialize(string text, int order);

	// produce a text in the style of the example
	virtual string generate(int size);

protected:
	string _data;
	map <vector <string>, vector <string>> k_grams;
	int _order;
	int _stream_size;
};

#endif