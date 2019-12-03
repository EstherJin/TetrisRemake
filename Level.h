//
// Created by Ordencia Wu on 2019-11-28.
//

#ifndef TETRIS_REMAKE_LEVEL_H
#define TETRIS_REMAKE_LEVEL_H

class Block1;

class Level {
protected:
    int lvl;
public:
    Level (int n);
    virtual char nextBlock() = 0;
    int getLevel();
    void changeLevel(int n);
};


#endif //TETRIS_REMAKE_LEVEL_H
