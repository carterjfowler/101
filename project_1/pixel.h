/*
    File Name: Pixel Class header file
    Author: Carter Fowler
    Course and Assignment: 262, Image Editor
    Description: class definition for a pixel class to store RGB values
*/

/***********************************************************
    class name: pixel
    stores RGB values to make 2D vector easier to understand
***********************************************************/

//create pixel class definition here
//pixel.h
#ifndef PIXEL_H
#define PIXEL_H

class pixel {
public:
    pixel(int r, int g, int b);
    void set_red(int r);
    void set_green(int g);
    void set_blue(int b);
    int get_red();
    int get_green();
    int get_blue();
private: 
    int _red;
    int _green;
    int _blue;
};

#endif