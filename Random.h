//
// Created by Ordencia Wu on 2019-11-28.
//

#ifndef TETRIS_REMAKE_RANDOM_H
#define TETRIS_REMAKE_RANDOM_H


#include "Level.h"

class Block1;

class Random: public Level {
public:
    virtual Block1 *nextBlock() = 0;
};


#endif //TETRIS_REMAKE_RANDOM_H
