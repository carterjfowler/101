/*
    clock_time.cpp

    Clock Time class cpp file for declarations

    Code for Data Structures lab 8, "Classes, Objects, and Operator Overloading"

    Author: Carter Fowler
*/

#include "clock_time.h"

int clock_time::get_hour() {
    //Get the hour part of the time
    return _seconds/3600;
}

int clock_time::get_minute() {
    //Get the minute part of the time
    return (_seconds%3600) / 60;
}

int clock_time::get_second() {
    //Get the second part of the time
    return _seconds%60;
}

void clock_time::set_time(int h, int m, int s) {
    //Set the time to the time that would exist at h hours, m minutes, and s seconds after midnight
    //allows for values above normal range
    _seconds = ((h * 3600) + (m * 60) + s)%86400;
}

clock_time::clock_time() {
    //Construct a clock_time object representing midnight
    _seconds = 0;
}

clock_time::clock_time(int h, int m, int s) {
    //Construct a clock_time object representing the same time as an object after calling set_time(h, m, s)
    set_time(h,m,s);
}

std::string to_string(clock_time c) {
    std::string hours = std::to_string(c.get_hour());
    std::string minutes = std::to_string(c.get_minute());
    if(minutes.size() == 1) minutes.insert(minutes.begin(), '0');
    
    std::string seconds = std::to_string(c.get_second());
    if(seconds.size() == 1) seconds.insert(seconds.begin(), '0');
    
    // if(nonmilitary) {
    //     if(c.get_hour() > 12) {
    //         hours = std::to_string(c.get_hour() - 12);
    //         return hours + ":" + minutes + ":" + seconds + " PM";
    //     } else {
    //         return hours + ":" + minutes + ":" + seconds + " AM";
    //     }
    // }
    
    return hours + ":" + minutes + ":" + seconds;
}

std::ostream& operator<<(std::ostream& out, clock_time c) {
    out << to_string(c);
}

bool operator==(const clock_time& a, const clock_time& b) {
    if(a._seconds == b._seconds) return true;
    else return false;
}

bool operator!=(const clock_time& a, const clock_time& b) {
    if(a._seconds == b._seconds) return false;
    else return true;
}

clock_time operator+(const clock_time& a, const clock_time& b) {
    int new_seconds = (a._seconds + b._seconds);
    int new_hours = new_seconds/3600;
    int new_minutes = (new_seconds%3600) / 60;
    new_seconds = new_seconds%60;
    return clock_time(new_hours, new_minutes, new_seconds);
}