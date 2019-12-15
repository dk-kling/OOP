#include "Tree.h"

Tree::Tree()
{
	Block_controller block_controller;
	Block* block_1 = block_controller.random_color_block(3, 11);
	piece.push_back(block_1);
	Block* block_2 = block_controller.random_color_block(3, 10);
	piece.push_back(block_2);
	Block* block_3 = block_controller.random_color_block(3, 9);
	piece.push_back(block_3);
}
