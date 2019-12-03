//
// Created by Ordencia Wu on 2019-11-30.
//

#ifndef TETRIS_REMAKE_LEVEL1_H
#define TETRIS_REMAKE_LEVEL1_H

#include "Random.h"

class Block1;

class Level1: public Random {
public:
    Level1 (unsigned seed);
    char nextBlock() override;
};


#endif //TETRIS_REMAKE_LEVEL1_H
