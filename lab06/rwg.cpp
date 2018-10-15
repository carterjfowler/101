/*
    rwg.cpp

    Author: C. Painter-Wakefield

    Created: 9/20/2017

    Class method definitions for the rwg class.
*/

#include "rwg.h"

#include <limits>
#include <cstdlib>
#include <ctime>

// initialize(istream &in)
//
// Read in all words from the istream and populate our dictionary, organized
// by the length of the words
void rwg::initialize(istream& in) {
	// initialize the random number generator to get a different
	// sequence every time
	srand(time(NULL));

	_words.clear();	// in case this object is re-used
	_min_length = 10000; // surely no words this long?
	_max_length = 0;

	string word;
	while (!in.eof()) {
		in >> word;
		int len = word.length();
		if (len != 0) {
			_words[len].push_back(word);
		}

		if (len < _min_length) _min_length = len;
		if (len > _max_length) _max_length = len;
	}
}

// is_empty()
//
// Return whether or not the dictionary has no words.
bool rwg::is_empty() {
	return _max_length == 0;
}

// generate(int n, ostream& out)
//
// Generate n random words and output on the provided ostream.
void rwg::generate(int n, ostream& out) {
	vector<int> lengths = _get_lengths(n);
	for (int len: lengths) {
		out << _get_word(len) << ' ';
	}
	out << endl;
}

// private helper methods

// _get_lengths(int n)
//
// Generate a vector of n random lengths between _min_length and _max_length
vector<int> rwg::_get_lengths(int n) {
	vector<int> lengths(n);
	for (int i = 0; i < n; i++) {
		// generate a random number between _min_length and _max_length
		int r = rand() % (_max_length - _min_length) + _min_length;
		while(true) {
			if(_words.count(r) != 0) {
				lengths[i] = r;
				break;
			} else {
				r = rand() % (_max_length - _min_length) + _min_length;
			}
		}
	}
	return lengths;
}

// _get_word(int len)
//
// Return one randomly selected word of length len
string rwg::_get_word(int len) {
	vector<string> possible_words = _get_words(len);
	
	// get a random word
	int idx = rand() % (possible_words.size());
	return possible_words[idx];
}

// _get_words(int len)
//
// Return all words of the specified length
vector<string> rwg::_get_words(int len) {
	return _words.at(len);
}
