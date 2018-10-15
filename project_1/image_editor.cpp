/*
        image_editor.cpp
        
        Method implementations for the image_editor class.

        author: C. Painter-Wakefield

        last modified: 1/15/2018
*/

#include <utility>
#include <iostream>
#include <iomanip>
#include <stack>

#include "image_editor.h"
#include "pixel.h"

using namespace std;

bool image_editor::load(istream& in) {
    // test magic string
    string magic;
    in >> magic;
    if (magic != "P3") return false;

    // TODO: get columns, rows, ensure valid
    //cols come before rows!!!
    in >> _cols;
    in >> _rows;
    if(!(_rows > 0 && _cols > 0)) {
        return false;
    }
    // TODO: get and discard color depth
    int color_depth;
    in >> color_depth;
    // TODO: initialize your image storage data structure
    // TODO: get image data from input stream into your data structure
    for(int i = 0; i < _rows; ++i) {
        vector<pixel> row;
        for(int j = 0; j < _cols; ++j) {
            int temp_red = 0;
            int temp_green = 0;
            int temp_blue = 0;
            in >> temp_red;
            in >> temp_green;
            in >> temp_blue;
            pixel temp_pixel(temp_red, temp_green, temp_blue);
            row.push_back(temp_pixel);
        }
        image_data.push_back(row);
    }
    
    return true;
}

void image_editor::save(ostream& out) {
    // TODO: output valid PPM file format data to the
    // output stream out
    cout << "P3" << endl;
    cout << _cols << " " << _rows << endl;
    cout << "255" << endl;
    //print out the data from the pixels
    for(int i = 0; i < _rows; ++i) {
        for(int j = 0; j < _cols; ++j) {
            cout << setprecision(3) << left << image_data[i][j].get_red() << " ";
            cout << image_data[i][j].get_green() << " ";
            cout << image_data[i][j].get_blue() << "   ";
        }
        cout << endl;
    }
}

int image_editor::get_rows() {
    // TODO: return the correct # of rows
    return _rows;
}

int image_editor::get_columns() {
    // TODO: return the correct # of columns
    return _cols;
}

int image_editor::get_red(int row, int col) {
    // TODO: return the actual pixel red value
    return image_data[row][col].get_red();
}

int image_editor::get_green(int row, int col) {
    // TODO: return the actual pixel green value
    return image_data[row][col].get_green();
}

int image_editor::get_blue(int row, int col) {
    // TODO: return the actual pixel blue value
    return image_data[row][col].get_blue();
}

void image_editor::apply_effect(int action_index) {
    enum action a = (enum action)action_index;

    // TODO: fill out this method
    if (a == GRAYSCALE) {
        // call a method that applies the grayscale
        // effect to the image in your data structure
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                int average = (image_data[i][j].get_red() + image_data[i][j].get_green() + image_data[i][j].get_blue()) / 3;
                image_data[i][j].set_red(average);
                image_data[i][j].set_green(average);
                image_data[i][j].set_blue(average);
            }
        }
    } else if (a == NEGATE_RED) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                int new_red = 255 - image_data[i][j].get_red();
                image_data[i][j].set_red(new_red);
            }
        }
    } else if (a == NEGATE_GREEN) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                int new_green = 255 - image_data[i][j].get_green();
                image_data[i][j].set_green(new_green);
            }
        }
    } else if (a == NEGATE_BLUE) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                int new_blue = 255 - image_data[i][j].get_blue();
                image_data[i][j].set_blue(new_blue);
            }
        }
    } else if (a == FLATTEN_RED) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                image_data[i][j].set_red(0);
            }
        }
    } else if (a == FLATTEN_GREEN) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                image_data[i][j].set_green(0);
            }
        }
    } else if (a == FLATTEN_BLUE) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                image_data[i][j].set_blue(0);
            }
        }
    } else if (a == EXTREME_CONTRAST) {
        for(int i = 0; i < _rows; ++i) {
            for(int j = 0; j < _cols; ++j) {
                //check for low numbers first
                if(image_data[i][j].get_red() <= 127) {
                    image_data[i][j].set_red(0);
                }
                if(image_data[i][j].get_green() <= 127) {
                    image_data[i][j].set_green(0);
                }
                if(image_data[i][j].get_blue() <= 127) {
                    image_data[i][j].set_blue(0);
                }
                //then check for high numbers
                if(image_data[i][j].get_red() > 127) {
                    image_data[i][j].set_red(255);
                }
                if(image_data[i][j].get_green() > 127) {
                    image_data[i][j].set_green(255);
                }
                if(image_data[i][j].get_blue() > 127) {
                    image_data[i][j].set_blue(255);
                }
            }
        }
    } else if (a == FLIP_HORIZONTAL) {
        for(int i = 0; i < _rows; ++i) {
            //create a vector to store flipped pixels
            vector<pixel> inverse_row;
            //populated with flipped values
            for(int j = (_cols - 1); j >= 0; --j) {
                inverse_row.push_back(image_data[i][j]);
            }
            //repopulate real vector with flipped numbers
            for(int j = 0; j < _cols; ++j) {
                image_data[i][j] = inverse_row[j];
            }
        }
    } else if (a == FLIP_VERTICAL) {
        for(int j = 0; j < _cols; ++j) {
            //create a vector to store flipped pixels
            vector<pixel> inverse_col;
            //populated with flipped values
            for(int i = (_rows - 1); i >= 0; --i) {
                inverse_col.push_back(image_data[i][j]);
            }
            //repopulate real vector with flipped numbers
            for(int i = 0; i < _rows; ++i) {
                image_data[i][j] = inverse_col[i];
            }
        }
    }
}

// TODO: add effect methods below here


