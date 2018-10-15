/*
    int_counter.h

    Base class for counters which work on integers.
*/
#pragma once
     
#include "counter.h"

class int_counter : public counter {
public:
    int_counter()                   { _value = 0; }
    virtual void increment()        { _value++; }
    virtual void reset()            { _value = 0; }
    virtual std::string to_string() { return std::to_string(_value); }
protected:
    unsigned int _value;
};

