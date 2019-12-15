#include "Map.h"

using namespace std;

Map::Map() {
    setScore(0);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            Block* empty_block = new Block(EMPTY, i, j);
            map[i][j] = empty_block;
        }
    }
}

Block* Map::getCurrent(int x, int y) {
    return map[x][y];
}

int Map::getScore() {
    return this->score;
}

void Map::setScore(int score) {
    this->score = score;
}

void Map::set_block(Block* block)
{
    this->map[block->get_x()][block->get_y()] = block;
}

bool Map::is_empty(int x, int y)
{
    return map[x][y]->get_color() == EMPTY;
}

bool Map::full_end_position()
{
    return (map[2][11]->get_color() != EMPTY
        || map[3][11]->get_color() != EMPTY);
}

