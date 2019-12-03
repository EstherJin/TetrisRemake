//
// Created by Ordencia Wu on 2019-12-01.
//

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height, int player) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }

    s = DefaultScreen(d);
    if (player == 1) {
        w = XCreateSimpleWindow(
                d, RootWindow(d, s), 10, 10, width, height,
                1, BlackPixel(d, s), WhitePixel(d, s)
        );
    } else {
        w = XCreateSimpleWindow(
                d, RootWindow(d, s), 800, 10, width, height,
                1, BlackPixel(d, s), WhitePixel(d, s)
        );
    }

    XSelectInput(d, w, ExposureMask | KeyPressMask);

    Pixmap pix = XCreatePixmap(
            d, w, width, height,
            DefaultDepth(d, DefaultScreen(d))
    );

    gc = XCreateGC(d, pix, 0, 0);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;

    const size_t numColours = 11;
    char color_vals[numColours][20] = {
            "PapayaWhip", "gray20", "MediumPurple3",
            "RoyalBlue4", "tomato4", "goldenrod1",
            "SeaGreen", "sienna1", "turquoise", "SaddleBrown", "White"
    };

    cmap = DefaultColormap(d, DefaultScreen(d));

    for(unsigned int i = 0; i < numColours; ++i) {
        XParseColor(d, cmap, color_vals[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d, gc, colours[gray20]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
    hints.height = hints.base_height = hints.min_height = hints.max_height = height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);

    // map window and flush
    XMapRaised(d, w);
    XFlush(d);

    // wait 1 second for setup
    sleep(1);
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
    XFlush(d);
}

void Xwindow::drawString(int x, int y, string msg) {
    XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
    XFlush(d);
}

/*void Xwindow::drawHeader(int level, int score, char next) {
    string lvl = "Level:                     ";
    lvl += to_string(level);
    string sc = "Score:                      ";
    sc += to_string(score)
    drawString(50, 15, lvl);
    drawString(50, 30, sc);

    string nt = "Next:";
    drawString (50, 500, nt);

    /*if (next != ' ') {
        switch (next) {
            case 'I':
                str += "           \nIIII       \n";
                fillRectangle()
                break;
            case 'J':
                str += "J          \nJJJ        \n";
                break;
            case 'L':
                str += "  L        \nLLL        \n";
                break;
            case 'O':
                str += "OO         \nOO         \n";
                break;
            case 'S':
                str += " SS        \nSS         \n";
                break;
            case 'Z':
                str += "ZZ         \n ZZ        \n";
                break;
            case 'T':
                str += "TTT        \n T         \n";
                break;
        }
    }
}*/


