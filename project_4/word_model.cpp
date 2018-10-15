#include "word_model.h"
#include <vector>
#include <sstream>

using namespace std;

void word_model::initialize(string text, int order) {
    _order = order;
    _data = text;
    //fix for looping around
    istringstream temp_words(text);
    for(int i = 0; i < _order; ++i) {
        string temp_looped_word;
        getline(temp_words, temp_looped_word, ' ');
        _data += temp_looped_word;
        _data += ' ';
    }
    
    //creation of vectors to be put into map
    istringstream words(_data);
    vector <string> temp_vector_key;
    string temp_string;
    for(int i = 0; i < _order; ++i) {
        getline(words, temp_string, ' ');
        temp_vector_key.push_back(temp_string);
    }
    vector <string> temp_vec;
    getline(words, temp_string, ' ');
    temp_vec.push_back(temp_string);
    k_grams.emplace(temp_vector_key, temp_vec);
    temp_vector_key.erase(temp_vector_key.begin());
    temp_vector_key.push_back(temp_string);
    _stream_size = _order + 1;
    while(!words.eof()) {
        getline(words, temp_string, ' ');
        if(k_grams.count(temp_vector_key) > 0) {
            k_grams[temp_vector_key].push_back(temp_string);
        } else {
            temp_vec.clear();
            temp_vec.push_back(temp_string);
            k_grams.emplace(temp_vector_key, temp_vec);
        }
        temp_vector_key.erase(temp_vector_key.begin());
        temp_vector_key.push_back(temp_string);
        _stream_size += 1;
    }
}

string word_model::generate(int size) {
    //find random start of to make seed
    int start = (rand() % _stream_size);
    string seed_start;
    //get start of seed
    istringstream words(_data);
    for(int i = 0; i < start; ++i) {
        getline(words, seed_start, ' ');
    }
    //get rest of seed
    vector <string> seed;
    for(int i = 0; i < _order; ++i) {
        string temp_string;
        getline(words, temp_string, ' ');
        seed.push_back(temp_string);
    }
    
    string answer = "";
    vector <string> temp_vec;
    
    //creating random string of requested size
    for(int i = 0; i < size; ++i) {
        temp_vec = k_grams[seed];
        int random_position = (rand() % temp_vec.size());
        answer += temp_vec[random_position] + " ";
        seed.erase(seed.begin());
        seed.push_back(temp_vec[random_position]);
    }
    
    return answer;
}