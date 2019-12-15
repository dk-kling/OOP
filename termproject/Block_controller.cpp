#include "Block_controller.h"

Block_controller::Block_controller() {}

Block* Block_controller::random_color_block(int x, int y) {
    Block* block = new Block((rand() % 4) + 1, x, y);
    return block;
}

Block* Block_controller::empty_block(int x, int y) {
    Block* block = new Block(EMPTY, x, y);
    return block;
}
