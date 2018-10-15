#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include <map>
#include <fstream>
    
using namespace std;
    
int main() {
    map<int, vector<string>> length_words;
    
    
    //read in dictionary.txt and emplace into map
    ifstream input("dictionary.txt");
    string word = "";
    int i = 0;
    int word_length = 0;
    while(!input.eof()) {
        input >> word;
        word_length = word.length();
        if(length_words.count(word_length) == 0) {
            //word length not in map yet, need to insert it
            vector<string> new_vec = {word};
            length_words.emplace(word_length, new_vec);
        } else {
            //word length is in vector
            length_words[word_length].push_back(word);
        }
    }
         
    int n = 0;
    while (true) {
        cout << "What length of word do you want? ";
        cin >> n;
        if (n == -1) break;
        
        if(length_words.count(n) > 0) {
            cout << "Here's a word: ";
            cout << length_words[n][rand() % length_words[n].size()];
            cout << endl;
        } else {
            cout << "Sorry, I don't seem to have a word of that length." << endl;
        }
    }
        
    return 0;
}
