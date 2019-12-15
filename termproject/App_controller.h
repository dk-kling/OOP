#ifndef TERMPROJECT_APPCONTROLLER_H
#define TERMPROJECT_APPCONTROLLER_H

#include <iostream>
#include <queue>
#include "Map.h"
#include "Piece_maker.h"

class App_controller {
private:
    Piece_maker piece_maker;
    Map map;
    Piece current;

    Map temp_map();
    void print_score();
    void show_map();

    void add_piece();

    void down_all();
    bool can_left();
    bool can_right();
    bool can_down();
    bool can_rotate();

    bool search_left(Block* block, int color);
    bool search_right(Block* block, int color);
    bool search_below(Block* block, int color);
    bool search_above(Block* block, int color);

    void puyo_drop();
    bool explode();
    bool check_current_end();
    void print_end();

    void input();
    void handle_command(char command);

public:
    App_controller();

    void run();
};


#endif //TERMPROJECT_APPCONTROLLER_H
