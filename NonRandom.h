//
// Created by Ordencia Wu on 2019-11-28.
//

#ifndef TETRIS_REMAKE_NONRANDOM_H
#define TETRIS_REMAKE_NONRANDOM_H


#include "Level.h"
#include <string>
class Block1;

class NonRandom: public Level {
    std::string fileName;
    std::string sequence;
public:
    NonRandom (std::string file, int n);
    char nextBlock() override;
};


#endif //TETRIS_REMAKE_NONRANDOM_H
