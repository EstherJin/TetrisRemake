//
// Created by Ordencia Wu on 2019-11-30.
//

#include "Level1.h"
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

Level1::Level1 (unsigned seed) : Random (1, seed) {}

char Level1::nextBlock() {
    char next;

    srand (seed);

    int number = rand() % 12 + 1;

    if (number == 1) {
        next = 'S';
    } else if (number == 2) {
        next = 'Z';
    } else if (number >= 3 && number <= 4) {
        next = 'I';
    } else if (number >= 5 && number <= 6) {
        next = 'T';
    } else if (number >= 7 && number <= 8) {
        next = 'J';
    } else if (number >= 9 && number <= 10) {
        next = 'L';
    } else if (number >= 11 && number <= 12) {
        next = 'O';
    }

    return next;
}