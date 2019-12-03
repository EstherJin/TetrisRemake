//
// Created by Ordencia Wu on 2019-12-01.
//

#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
    Display *d;
    Window w;
    int s;
    GC gc;
    unsigned long colours[11];
    int player;

public:
    Xwindow(int width=405, int height=780, int player=1);  // Constructor; displays the window.
    ~Xwindow();                              // Destructor; destroys the window.
    Xwindow(const Xwindow&) = delete;
    Xwindow &operator=(const Xwindow&) = delete;

    enum {PapayaWhip=0, gray20, MediumPurple3,
        RoyalBlue4, tomato4, goldenrod1,
        SeaGreen, sienna1, turquoise, SaddleBrown, White}; // Available colours.

    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, int colour=PapayaWhip);

    // Draws a string
    void drawString(int x, int y, std::string msg);
};

#endif


