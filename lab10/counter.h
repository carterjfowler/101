/*
    counter.h
  
    Abstract base class modeling a simple additive counter.
*/

#pragma once

#include <string>

class counter {
public:
    virtual void increment()        = 0;
    virtual void reset()            = 0;
    virtual std::string to_string() = 0;
};

