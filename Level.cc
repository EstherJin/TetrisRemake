//
// Created by Ordencia Wu on 2019-11-28.
//

#include "Level.h"
#include "block1.h"

Level::Level (int n): lvl(n) {}

int Level::getLevel() {
    return lvl;
}

void Level::changeLevel(int n) {
    lvl = n;
}