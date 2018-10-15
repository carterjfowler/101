#ifndef _HANGMAN_H
#define _HANGMAN_H

/*
    hangman.h
        
    Class definition for the hangman class.

    assignment: CSCI 262 Project - Evil Hangman        

    author: Carter Fowler

    last modified: 3/3/2018
*/

#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

/******************************************************************************
   class hangman

   Maintains game state for a game of hangman.

******************************************************************************/

class hangman {
public:
    hangman();

    // start a new game where player gets num_guesses unsuccessful tries
	void start_new_game(int num_guesses);

    // player guesses letter c; return whether or not char is in word
    bool process_guess(char c);

    // display current state of word - guessed characters or '-'
    string get_display_word();

    // How many guesses remain?
	int get_guesses_remaining();

    // What characters have already been guessed (for display)?
    string get_guessed_chars();

    // Has this character already been guessed?
    bool was_char_guessed(char c);

    // Has the game been won/lost?  (Else, it continues.)
    bool is_won();
    bool is_lost();

    // Return the true hidden word.
    string get_hidden_word();
    
    //return the size of possible words
    int get_list_size();
private:
    map<int, set<string>> dictionary;
    int guesses;
    set<char> guessed_letters;
    int word_length;
    vector<string> possible_words;
    map<string, set<string>> word_families;
    string current_word;
    set<char> correct_guesses;
};

#endif
