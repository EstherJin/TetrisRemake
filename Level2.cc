//
// Created by Ordencia Wu on 2019-11-30.
//

#include "Level2.h"
#include "block1.h"
#include <stdlib.h>
#include <iostream>
#include "l.h"
#include "t.h"
#include "i.h"
#include "z.h"
#include "j.h"
#include "s.h"
#include "o.h"

Level2::Level2 () : Random (2) {}

Block1 *Level2::nextBlock() {
    Block1 *next;

    srand (time(NULL));

    int number = rand() % 7 + 1;

    if (number == 1) {
        next = new S ();
    } else if (number == 2) {
        next = new Z ();
    } else if (number == 3) {
        next = new I ();
    } else if (number == 4) {
        next = new T ();
    } else if (number == 5) {
        next = new J ();
    } else if (number == 6) {
        next = new L ();
    } else if (number == 7) {
        next = new O ();
    }
}