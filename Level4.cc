//
// Created by Ordencia Wu on 2019-11-30.
//

#include "Level4.h"
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

Level4::Level4 () : Random (4) {}

Block1 *Level4::nextBlock() {
    Block1 *next;

    srand (time(NULL));

    int number = rand() % 9 + 1;

    if (number == 1) {
        next = new I ();
    } else if (number == 2) {
        next = new T ();
    } else if (number == 3) {
        next = new J ();
    } else if (number == 4) {
        next = new L ();
    } else if (number == 5) {
        next = new O ();
    } else if (number >= 6 && number <= 7) {
        next = new S ();
    } else if (number >= 8 && number <= 9) {
        next = new Z ();
    }
}