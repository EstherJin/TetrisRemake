//
// Created by Ordencia Wu on 2019-12-01.
//

#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "window.h"
#include "observer.h"
#include "state.h"
#include <memory>

class GraphicsDisplay: public Observer {
    const int cellLength = 34;
    const int row = 18;
    const int col = 11;
    const int xmar = 15;
    const int ymar = 65;
    //bool
    std::unique_ptr<Xwindow> window;
    //~GraphicsDisplay();

public:
    GraphicsDisplay();
    //GraphicsDisplay (int level, int score, bool blind, char next);
    void notify (Subject &whoNotified) override;
    void printLevel(int level);
    void printScore(int score);
    void printNext (char next);
    void blind();
};

#endif
