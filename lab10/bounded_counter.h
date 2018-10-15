/*
    bounded_counter.h

    This counter will count up to a fixed bound, and then go no further.
*/

#pragma once

#include "int_counter.h"

class bounded_counter : public int_counter {
public:
    bounded_counter(int b) {
        _value = 0; 
        _max_value = b;
    }
    virtual void increment() { 
        if(_value < _max_value) {
            _value++;
        }
    }
    virtual void reset()            { _value = 0; }
    virtual std::string to_string() { return std::to_string(_value); }
protected:
    unsigned int _value;
    unsigned int _max_value;
};