#ifndef TERMPROJECT_PIECE_H
#define TERMPROJECT_PIECE_H

#include "Block_controller.h"
#include <vector>

using namespace std;

#define NONE 0
#define FOLD 1
#define TREE 2
#define CROSS 3

class Piece {
private:
    int num_rot = 0;
    int type = NONE;
public:

    vector<Block*> piece;

    Piece();
    int get_type();
    void set_type(int _type);
    int get_num_rot();
    void set_num_rot(int num);
    void set_piece(vector<Block*> piece);
    vector<Block*> get_piece();

    void down();
    void left();
    void right();
    void rotate();
};


#endif //TERMPROJECT_BLOCK_H