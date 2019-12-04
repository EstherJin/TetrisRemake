//
// Created by Ordencia Wu on 2019-12-01.
//

#include "graphicsDisplay.h"
#include "observer.h"
#include "cell.h"
#include "state.h"
#include "window.h"
#include <memory>
#include <string>
using namespace std;

GraphicsDisplay::GraphicsDisplay ()  {

    window = make_unique<Xwindow> ();

    window->fillRectangle(0,0,405,780,0);
    window->fillRectangle(0,50,405,642,9);
    window->fillRectangle(15,65,375,612,0);
    for (int i = 1; i < row; i++) {
        window->fillRectangle(xmar,ymar+i*34,375,1,10);
    }
    for (int j = 1; j < col; j++) {
        window->fillRectangle(xmar+j*34,ymar,1,612,10);
    }
    // window->fillRectangle(0, 0, 100, 100, 4);

    string nt = "Next:";
    window->drawString (15, 700, nt);
}

void GraphicsDisplay::notify (Subject &whoNotified) {
    State st = whoNotified.getState();

    if (st.add) {
        if (st.type == 'T') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 2);
        } else if (st.type == 'L') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 3);
        } else if (st.type == 'Z') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 4);
        } else if (st.type == 'O') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 5);
        } else if (st.type == 'S') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 6);
        } else if (st.type == 'J') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 7);
        } else if (st.type == 'I') {
            window->fillRectangle(xmar + st.coords.col * cellLength,
                                  ymar + st.coords.row * cellLength,
                                  cellLength, cellLength, 8);
        }
    } else {
        window->fillRectangle(xmar + st.coords.col * cellLength,
                              ymar + st.coords.row * cellLength,
                              cellLength, cellLength, 0);

        for (int i = 1; i < row; i++) {
            window->fillRectangle(xmar,ymar+i*34,375,1,10);
        }
        for (int j = 1; j < col; j++) {
            window->fillRectangle(xmar+j*34,ymar,1,612,10);
        }

    }
    for (int i = 1; i < row; i++) {

        window->fillRectangle(xmar,ymar+i*34,375,1,10);
    }
    for (int j = 1; j < col; j++) {
        window->fillRectangle(xmar+j*34,ymar,1,612,10);
    }


}

void GraphicsDisplay::printLevel(int level) {
    window->fillRectangle(0,0,405,1,0);
    string lvl = "Level:                    ";
    lvl += to_string(level);
    window->drawString(50, xmar, lvl);
}

void GraphicsDisplay::printScore(int score) {
    window->fillRectangle(0,30,405,1,0);
    string sc = "Score:                     ";
    sc += to_string(score);
    window->drawString(50, 30, sc);
}

void GraphicsDisplay::printNext (char next) {
    if (next != ' ') {
        switch (next) {
            case 'T':
                window->fillRectangle(xmar,712, cellLength, cellLength, 2);
                window->fillRectangle(xmar+cellLength,712, cellLength, cellLength, 2);
                window->fillRectangle(xmar+2*cellLength,712, cellLength, cellLength, 2);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 2);
            case 'L':
                window->fillRectangle(xmar+2*cellLength,712, cellLength, cellLength, 3);
                window->fillRectangle(xmar,712+cellLength, cellLength, cellLength, 3);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 3);
                window->fillRectangle(xmar+2*cellLength,712+cellLength, cellLength, cellLength, 3);
            case 'Z':
                window->fillRectangle(xmar,712, cellLength, cellLength, 4);
                window->fillRectangle(xmar+cellLength,712, cellLength, cellLength, 4);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 4);
                window->fillRectangle(xmar+2*cellLength,712+cellLength, cellLength, cellLength, 4);
            case 'O':
                window->fillRectangle(xmar,712, cellLength, cellLength, 5);
                window->fillRectangle(xmar+cellLength,722,cellLength, cellLength, 5);
                window->fillRectangle(xmar,712+cellLength, cellLength, cellLength, 5);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 5);
            case 'S':
                window->fillRectangle(xmar+cellLength,712, cellLength, cellLength, 6);
                window->fillRectangle(xmar+2*cellLength,712, cellLength, cellLength, 6);
                window->fillRectangle(xmar,712+cellLength, cellLength, cellLength, 6);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 6);
            case 'J':
                window->fillRectangle(xmar,712, cellLength, cellLength, 7);
                window->fillRectangle(xmar,712+cellLength, cellLength, cellLength, 7);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 7);
                window->fillRectangle(xmar+2*cellLength,712+cellLength, cellLength, cellLength, 7);
            case 'I':
                window->fillRectangle(xmar,712+cellLength, cellLength, cellLength, 8);
                window->fillRectangle(xmar+cellLength,712+cellLength, cellLength, cellLength, 8);
                window->fillRectangle(xmar+2*cellLength,712+cellLength, cellLength, cellLength, 8);
                window->fillRectangle(xmar+3*cellLength,712+cellLength, cellLength, cellLength, 8);
        }
    } else {
        window->fillRectangle(xmar, 712, 405, 150, 0);
    }
}