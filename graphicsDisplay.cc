//
// Created by Ordencia Wu on 2019-12-01.
//

#include "graphicsDisplay.h"
#include "observer.h"
#include "cell.h"
#include "info.h"
#include "state.h"
#include "window.h"
#include <memory>
#include <string>
using namespace std;

GraphicsDisplay::GraphicsDisplay ()  {

    window = make_unique<Xwindow> ();

    window->fillRectangle(0,0,405,817,0);
    window->fillRectangle(0,50,405,642,9);
    window->fillRectangle(15,75,375,612,0);
    for (int i = 1; i < row; i++) {
        window->fillRectangle(15,75+i*34,375,1,10);
    }
    for (int j = 1; j < col; j++) {
        window->fillRectangle(15+j*34,75,1,612,10);
    }

    string nt = "Next:";
    drawString (50, 692, nt);
}

void GraphicsDisplay::notify (Subject &whoNotified) {
    State st = whoNotified.getState();

    if (st.add) {
        if (st.type == 'T') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 2);
        } else if (st.type == 'L') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 3);
        } else if (st.type == 'Z') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 4);
        } else if (st.type == 'O') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 5);
        } else if (st.type == 'S') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 6);
        } else if (st.type == 'J') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 7);
        } else if (st.type == 'I') {
            window->fillRectangle(15 + st.coords.col * cellLength,
                                  75 + st.coords.row * cellLength,
                                  cellLength, cellLength, 8);
        }
    } else {
        window->fillRectangle(15 + st.coords.col * cellLength,
                              75 + st.coords.row * cellLength,
                              cellLength, cellLength, 0)
    }


}

void GraphicsDisplay::printLevel(int level) {
    window->fillRectangle(0,0,405,1,0);
    string lvl = "Level:                    ";
    lvl += to_string(level);
    window->drawString(50, 15, lvl);
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
                window->fillRectangle(15,712, cellLength, cellLength, 2);
                window->fillRectangle(15+cellLength,712, cellLength, cellLength, 2);
                window->fillRectangle(15+2*cellLength,712, cellLength, cellLength, 2);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 2);
            case 'L':
                window->fillRectangle(15+2*cellLength,712, cellLength, cellLength, 3);
                window->fillRectangle(15,712+cellLength, cellLength, cellLength, 3);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 3);
                window->fillRectangle(15+2*cellLength,712+cellLength, cellLength, cellLength, 3);
            case 'Z':
                window->fillRectangle(15,712, cellLength, cellLength, 4);
                window->fillRectangle(15+cellLength,712, cellLength, cellLength, 4);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 4);
                window->fillRectangle(15+2*cellLength,712+cellLength, cellLength, cellLength, 4);
            case 'O':
                window->fillRectangle(15,712, cellLength, cellLength, 5);
                window->fillRectangle(15+cellLength,722,cellLength, cellLength, 5);
                window->fillRectangle(15,712+cellLength, cellLength, cellLength, 5);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 5);
            case 'S':
                window->fillRectangle(15+cellLength,712, cellLength, cellLength, 6);
                window->fillRectangle(15+2*cellLength,712, cellLength, cellLength, 6);
                window->fillRectangle(15,712+cellLength, cellLength, cellLength, 6);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 6);
            case 'J':
                window->fillRectangle(15,712, cellLength, cellLength, 7);
                window->fillRectangle(15,712+cellLength, cellLength, cellLength, 7);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 7);
                window->fillRectangle(15+2*cellLength,712+cellLength, cellLength, cellLength, 7);
            case 'I':
                window->fillRectangle(15,712+cellLength, cellLength, cellLength, 8);
                window->fillRectangle(15+cellLength,712+cellLength, cellLength, cellLength, 8);
                window->fillRectangle(15+2*cellLength,712+cellLength, cellLength, cellLength, 8);
                window->fillRectangle(15+3*cellLength,712+cellLength, cellLength, cellLength, 8);
        }
    }
}
