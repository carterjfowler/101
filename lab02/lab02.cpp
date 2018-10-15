/* CSCI 262 Lab 2: String practice
 *
 * Author: Carter Fowler
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    //task number 2
    
    // ifstream input("haiku.txt");
    // ofstream output("haiku2.txt");
    
    // string test = "";
    // while(!input.eof()) {
    //     getline(input, test);   //this is how you get the entire line from a file, out the variable name of the file in place of cin
    //     cout << test << endl;
    //     output << test << endl;
    // }
    
    // input.close();
    // output.close();
    
    
    //task number 3
    
    //finish final step later!!!
    
    // string userInput = "";
    
    // cout << "Please enter a string: ";
    // getline(cin, userInput);
    
    // istringstream test(userInput);
    
    // string output = "";
    // while(!test.eof()) {
    //     test >> output;
    //     cout << output << endl;
    // }
    
    ifstream input("lines.txt");
    //FIXME!!!!!!
    //figure out why i need the number of lines, try using a for loop
    int numLines;
    string longestWord = "";
    int lineNum;
    input >> numLines;
    cin.clear();
    
    string lineInput = "";
    int i = 0;
    while(!input.eof()) {
        ++i;
        getline(input, lineInput);
        istringstream words(lineInput);
        string newWord = "";
        while(!words.eof()) {
            words >> newWord;
            if(newWord.length() > longestWord.length()) {
                longestWord = newWord;
                lineNum = i;
            }
        }
    }
    
    cout << "The longest word is: " << longestWord << endl;
    cout << "The line number is: " << lineNum << endl;
    
    return 0;
}