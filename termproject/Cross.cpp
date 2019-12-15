#include "Cross.h"

Cross::Cross()
{
	Block_controller block_controller;
	Block* block_1 = block_controller.random_color_block(3, 10);
	piece.push_back(block_1);
	Block* block_2 = block_controller.random_color_block(2, 10);
	piece.push_back(block_2);
	Block* block_3 = block_controller.random_color_block(3, 9);
	piece.push_back(block_3);
	Block* block_4 = block_controller.random_color_block(4, 10);
	piece.push_back(block_4);
	Block* block_5 = block_controller.random_color_block(3, 11);
	piece.push_back(block_5);
}
