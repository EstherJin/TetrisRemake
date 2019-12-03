//
// Created by Ordencia Wu on 2019-11-28.
//

#include "textDisplay.h"
#include "sstream"
#include <iostream>
#include "string"
using namespace std;

void TextDisplay::print (ostream &out, string str1, string str2) {
    istringstream ss1 {str1};
    istringstream ss2 {str2};

    string board1;
    string board2;

    while (getline(ss1, board1) && getline(ss2, board2)) {
        out << board1;
        out << "          ";
        out << board2;
        out << endl;
    }
}