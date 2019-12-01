//
// Created by Ordencia Wu on 2019-11-30.
//

#ifndef TETRIS_REMAKE_LEVEL2_H
#define TETRIS_REMAKE_LEVEL2_H

#include "Random.h"
class Block1;

class Level2: public Random {
public:
    Level2 ();
    Block1 *nextBlock() override;
};


#endif //TETRIS_REMAKE_LEVEL2_H
