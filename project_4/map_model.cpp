#include "map_model.h"

using namespace std;

void map_model::initialize(string text, int order) {
    _order = order;
    //loop the text around
    _data = text + text.substr(0, order);
    //fill map
    for(int i = 0; i < _data.size(); ++i) {
        if(k_grams.count(_data.substr(i, order)) > 0) {
            k_grams[_data.substr(i, order)].push_back(_data[i + order]);
        } else {
            vector <char> temp_vec;
            temp_vec.push_back(_data[i + order]);
            k_grams.emplace(_data.substr(i, order), temp_vec);
        }
    }
}

string map_model::generate(int size) {
    //find random start to make seed
    int start = (rand() % (_data.length() - _order));
	string seed = _data.substr(start, _order);
	
	string answer = "";
	vector <char> temp_vec;
	
	//creating random string of requested size
	for(int i = 0; i < size; ++i) {
	    temp_vec = k_grams[seed];
	    int random_position = (rand() % temp_vec.size());
	    answer += temp_vec[random_position];
	    seed = seed.substr(1) + temp_vec[random_position];
	}
	return answer;
}