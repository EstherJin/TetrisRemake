//
// Created by Ordencia Wu on 2019-11-30.
//

#ifndef TETRIS_REMAKE_LEVEL3_H
#define TETRIS_REMAKE_LEVEL3_H

#include "Random.h"
class Block1;

class Level3: public Random {
public:
    Level3 (unsigned seed);
    Block1 *nextBlock () override;
};


#endif //TETRIS_REMAKE_LEVEL3_H
