/*
    bit_counter.h

    A counter which uses a string of zeros and ones to simulate binary
    counting.  Bit counters can be created for any desired width (in bits).
*/
#pragma once

#include "counter.h"

class bit_counter : public counter {
public:
    bit_counter()                   { _width = 8; reset(); }
    bit_counter(unsigned int w)     { _width = w; reset(); }
    virtual void reset()            { _bits = std::string(_width, '0'); }
    virtual std::string to_string() { return _bits; }

    virtual void increment() {
        unsigned int pos = _width - 1;
        while (pos > 0 && _bits[pos] == '1') {
            _bits[pos] = '0';
            pos--;
        }
        if (pos == 0 && _bits[0] == '1') {
           _bits[0] = '0';
        } else {
           _bits[pos] = '1';
        }
    }
    
private:
    unsigned int _width;
    std::string _bits;
};

