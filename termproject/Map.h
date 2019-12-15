#ifndef TERMPROJECT_MAP_H
#define TERMPROJECT_MAP_H


#include "Block.h"

#define HEIGHT 12
#define WIDTH 6

class Map {
private:
    Block* map[WIDTH][HEIGHT];
    int score;

public:
    Map();
    Block* getCurrent(int x, int y);
    int getScore();
    void setScore(int score);
    void set_block(Block* block);
    bool is_empty(int x, int y);
    bool full_end_position();
};


#endif //TERMPROJECT_MAP_H