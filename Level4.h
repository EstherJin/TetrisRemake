//
// Created by Ordencia Wu on 2019-11-30.
//

#ifndef TETRIS_REMAKE_LEVEL4_H
#define TETRIS_REMAKE_LEVEL4_H

#include "Random.h"

class Block1;

class Level4: public Random {
public:
    Block1 *nextBlock () override;
};


#endif //TETRIS_REMAKE_LEVEL4_H
