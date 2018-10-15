/*
    mod_counter.h

    A mod_counter is an int counter which rolls over at a given modulus.
*/
#pragma once

#include "int_counter.h"

class mod_counter : public int_counter {
public:
    mod_counter(unsigned int m) { _modulus = m; } 

    virtual void increment() { 
        if (_value == _modulus - 1) _value = 0;
        else _value++;
    }

private:
    unsigned int _modulus;
};

