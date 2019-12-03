//
// Created by Ordencia Wu on 2019-11-30.
//

#include "Level3.h"
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

Level3::Level3 (unsigned seed) : Random (3, seed) {}

char Level3::nextBlock() {
    char next;

    srand (seed);

    int number = rand() % 9 + 1;

    if (number == 1) {
        next = 'I';
    } else if (number == 2) {
        next = 'T';
    } else if (number == 3) {
        next = 'J';
    } else if (number == 4) {
        next = 'L';
    } else if (number == 5) {
        next = 'O';
    } else if (number >= 6 && number <= 7) {
        next = 'S';
    } else if (number >= 8 && number <= 9) {
        next = 'Z';
    }

    return next;
}