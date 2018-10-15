/*
    clock_time.h

    Clock Time class header file

    Code for Data Structures lab 8, "Classes, Objects, and Operator Overloading"

    Author: Carter Fowler
*/

#pragma once
#include <string>

class clock_time {
    public:
        friend std::string to_string(clock_time c);
        friend std::ostream& operator<<(std::ostream& out, clock_time c);
        friend bool operator==(const clock_time& a, const clock_time& b);
        friend bool operator!=(const clock_time& a, const clock_time& b);
        friend clock_time operator+(const clock_time& a, const clock_time& b);
        
        int get_hour();
        int get_minute();
        int get_second();
        void set_time(int h, int m, int s);
        clock_time();
        clock_time(int h, int m, int s);
    private:
        int _seconds;  //number of seconds past midnight
        bool nonmilitary = false;
};

std::ostream& operator<<(std::ostream& out, clock_time c);
std::string to_string(clock_time c);
bool operator==(const clock_time& a, const clock_time& b);
bool operator!=(const clock_time& a, const clock_time& b);
clock_time operator+(const clock_time& a, const clock_time& b);