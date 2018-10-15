/*
    File Name: Pixel Class cpp file
    Author: Carter Fowler
    Course and Assignment: 262, Image Editor
    Description: class declaration for a pixel class to store RGB values
*/

/************************************************************
    class name: pixel
    stores RGB values to make 2D vector easier to understand
************************************************************/

//declare pixel class components

#include "pixel.h"
#include <iostream>

using namespace std;

pixel::pixel(int r, int g, int b) {
    _red = r;
    _green = g;
    _blue = b;
}

void pixel::set_red(int r) {
    _red = r;
}

void pixel::set_green(int g) {
    _green = g;
}

void pixel::set_blue(int b) {
    _blue = b;
}

int pixel::get_red() {
    return _red;
}

int pixel::get_green() {
    return _green;
}

int pixel::get_blue() {
    return _blue;
}