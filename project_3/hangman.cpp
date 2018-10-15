/*
    hangman.cpp
        
    Method implementations for the hangman class.
    
    assignment: CSCI 262 Project - Evil Hangman        

    author: Carter Fowler

    last modified: 3/3/2018
*/

#include "hangman.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// constructor
hangman::hangman() { 
    // TODO: Read in and store words from dictionary.txt
    // TODO: Initialize game state variables
    ifstream input("dictionary.txt");
    string word = "";
    while(!input.eof()) {
        input >> word;
        int length = word.length();
        if(dictionary.count(length) == 0) {
            set<string> temp_set;
            temp_set.insert(word);
            dictionary.emplace(length, temp_set);
        } else {
            dictionary[length].insert(word);
        }
    }
    input.close();
    
    //possibly more, not sure yet, we'll see
    guesses = 0;
    word_length = 0;
}


//DONE
//Works? - 

// start_new_game()
//
// Setup a new game of hangman.
void hangman::start_new_game(int num_guesses) {
    guesses = num_guesses;
    possible_words.clear();
    current_word = "";
    cout << "How long do you want the word to be? ";
    while(true) {
        cin >> word_length;
        if(dictionary.count(word_length) != 0) {
            break;
        }
        cout << "Sorry that length is not valid. Please another length: ";
    }
    cin.ignore(1, '\n');
    for(int i = 0; i < word_length; ++i) {
        current_word += "-";
    }
    vector<string> temp_vector;
    for(auto set_iterator: dictionary[word_length]) {   //convert set to vector
        temp_vector.push_back(set_iterator);
    }
    possible_words = temp_vector;
    guessed_letters.clear();
    word_families.clear();
    correct_guesses.clear();
}


// process_guess()
//
// Process a player's guess - should return true/false depending on whether
// or not the guess was in the hidden word.  If the guess is incorrect, the
// remaining guess count is decreased.
bool hangman::process_guess(char c) {
    //iterate over possible_words to make word families based on guess
    word_families.clear();
    guessed_letters.insert(c);
    for(int i = 0; i < possible_words.size(); ++i) {  //iterate over vector of possible words
        string temp_word = "";
        for(int j = 0; j < possible_words[i].size(); ++j) {  //iterate over that string to create 
            if(possible_words[i][j] == c || correct_guesses.count(possible_words[i][j]) != 0) {     //if it is guessed char, put in family
                temp_word += possible_words[i][j];
            } else {
                temp_word += "-";
            }
        }
        if(word_families.count(temp_word) == 0) {
            set<string> temp_set;
            temp_set.insert(possible_words[i]);
            word_families.emplace(temp_word, temp_set);
        } else {
            word_families[temp_word].insert(possible_words[i]);
        }
    }
    
    //now find the largest word family and see if guess is in it
    int largest_size = 0;
    string largest_size_key = "";
    int largest_empty_size = 0;
    for(auto map_iterator: word_families) {
        if(map_iterator.second.size() > largest_size) {
            largest_size = map_iterator.second.size();
            largest_size_key = map_iterator.first;
        }
    }
    vector<string> temp_vector;
    current_word = largest_size_key;
    for(auto set_iterator: word_families[largest_size_key]) {   //convert set to vector
        temp_vector.push_back(set_iterator);
    }
    possible_words = temp_vector;
    for(auto x: largest_size_key) {
        if(x == c) {
            correct_guesses.insert(x);
            return true;
        }
    }
    --guesses;
    return false;
}


//DONE
//Works? - 

// get_display_word()
//
// Return a representation of the hidden word, with unguessed letters
// masked by '-' characters.
string hangman::get_display_word() {
    return current_word;
}


//DONE
//Works? - 

// get_guesses_remaining()
//
// Return the number of guesses remaining for the player.
int hangman::get_guesses_remaining() {
    return guesses;
}


//DONE
//Works? - 

// get_guessed_chars()
//
// What letters has the player already guessed?  Return in alphabetic order.
string hangman::get_guessed_chars() {
    string guessed_chars = "";
    for(auto set_iterator: guessed_letters) {
        guessed_chars += set_iterator;
    }
    return guessed_chars;
}


//DONE
//Works? - 

// was_char_guessed()
//
// Return true if letter was already guessed.
bool hangman::was_char_guessed(char c) {
    if(guessed_letters.count(c) > 0) {
        return true;
    } else return false;
}


// is_won()
//
// Return true if the game has been won by the player.
bool hangman::is_won() {
    //check if list is only one, if so check if user is right
    if(possible_words.size() == 1 && current_word == possible_words[0]) {
        return true;
    } else return false;
}


// is_lost()
//
// Return true if the game has been lost.
bool hangman::is_lost() {
    //check if guesses == 0
    if(guesses == 0 && !is_won()) return true;
    return false;
}


//DONE
//Works? - 

// get_hidden_word
//
// Return the true hidden word to show the player.
string hangman::get_hidden_word() {
    //find random word from list and return it
    if(is_lost()) {
        srand(time(0));
        int word_place = (rand() % possible_words.size());
        return possible_words[word_place];
    }
    return possible_words[0];
}

int hangman::get_list_size() {
    return possible_words.size();
}