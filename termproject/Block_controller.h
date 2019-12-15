#ifndef TERMPROJECT_BLOCK_CONTROLLER_H
#define TERMPROJECT_BLOCK_CONTROLLER_H

#include <cstdlib>
#include <ctime>

#include "Block.h"

class Block_controller {
public:
    Block_controller();
    Block* random_color_block(int x, int y);
    Block* empty_block(int x, int y);
};


#endif //TERMPROJECT_BLOCK_CONTROLLER_H