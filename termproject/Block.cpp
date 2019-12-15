#include "Block.h"

Block::Block(int color, int x, int y) {
    this->set_x(x);
    this->set_y(y);
    this->color = color;
}

Block::~Block() {}

int Block::get_color() {
    return this->color;
}

int Block::get_x() {
    return this->x;
}

int Block::get_y() {
    return this->y;
}

void Block::set_color(int color)
{
    this->color = color;
}


void Block::set_x(int x)
{
    this->x = x;
}

void Block::set_y(int y)
{
    this->y = y;
}

void Block::down()
{
    set_y(get_y() - 1);
}

void Block::left()
{
    set_x(get_x() - 1);
}

void Block::right()
{
    set_x(get_x() + 1);
}

