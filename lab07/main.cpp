#include <iostream>
#include <cmath>

using namespace std;



int main() {
    //Babylonian Method
    double number(0), guess(0);
    cout << "Enter a number: ";
    cin >> number;
    cout << "What is your guess? ";
    cin >> guess;
    
    double high_end, low_end, previous_guess;
    
    //dont forget to find out which one is high_end to determine how to calculate the difference of two guesses
    while(true) {
        previous_guess = guess;
        if(pow(previous_guess, 2) > number) {
            high_end = guess;
            low_end = number/high_end;
            
            guess = (high_end + low_end) / 2.0;
            
            cout << guess << endl;
            
            if((previous_guess - guess) < 0.00000001) {
                break;
            }
        } else {
            low_end = guess;
            high_end = number/low_end;
            
            guess = (high_end + low_end) / 2.0;
            
            cout << guess << endl;
            
            if((guess - previous_guess) < 0.00000001) {
                break;
            }
        }
    }
    
    return 0;
}