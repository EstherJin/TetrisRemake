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

Level2::Level2 (unsigned seed) : Random (2,seed) {}

char Level2::nextBlock() {
    char next;

    srand (seed);

    int number = rand() % 7 + 1;

    if (number == 1) {
        next = 'S';
    } else if (number == 2) {
        next = 'Z';
    } else if (number == 3) {
        next = 'I';
    } else if (number == 4) {
        next = 'T';
    } else if (number == 5) {
        next = 'J';
    } else if (number == 6) {
        next = 'L';
    } else if (number == 7) {
        next = 'O';
    }

    return next;
}