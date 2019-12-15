#ifndef TERMPROJECT_BLOCK_H
#define TERMPROJECT_BLOCK_H

#define EMPTY 0
#define GREY 1
#define RED 2
#define GREEN 3
#define BLUE 4

class Block {
private:
    int color;
    int x, y;

public:
    Block(int color, int x, int y);
    ~Block();

    int get_color();
    int get_x();
    int get_y();
    void set_color(int color);
    void set_x(int x);
    void set_y(int y);
    void down();
    void left();
    void right();
};


#endif //TERMPROJECT_BLOCK_H