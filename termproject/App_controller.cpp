#include "App_controller.h"

using namespace std;

App_controller::App_controller()
{
    piece_maker = Piece_maker();
    map = Map();
    current = piece_maker.make_piece();
}

void App_controller::show_map() {
    print_score();

    Map temp_m = temp_map();
    
    vector<Block*> temp_v = current.get_piece();
    vector<Block*>::iterator iter;
    
    cout << "========================" << endl;
    for (int j = HEIGHT - 1; j >= 0; j--) {
        cout << "||  ";
        for (int i = 0; i < WIDTH; i++) {
            cout << temp_m.getCurrent(i, j)->get_color() << "  ";
        }
        cout << "||" << endl;
    }
    cout << "========================" << endl;
}

Map App_controller::temp_map()
{
    Map temp_m = this->map;
    vector<Block*> temp = current.get_piece();
    vector<Block*>::iterator iter;

    for (iter = temp.begin(); iter != temp.end(); ++iter) {
        temp_m.set_block((*(iter)));
    }
    return temp_m;
}

void App_controller::print_score() {
    cout << "score : " << map.getScore() << "\n" << endl;
}

void App_controller::add_piece()
{
    vector<Block*> temp_v = current.get_piece();
    vector<Block*>::iterator iter;
    for (iter = temp_v.begin(); iter != temp_v.end(); ++iter) {
        map.set_block((*(iter)));
    }
}

void App_controller::down_all()
{
    Map temp_m = temp_map();
    vector<Block*> temp = current.get_piece();
    vector<Block*>::iterator iter;

    for (iter = temp.begin(); iter != temp.end(); ++iter) {
        while ((*(iter))->get_y() - 1 >= 0
            && temp_m.is_empty((*(iter))->get_x(), (*(iter))->get_y() - 1))
            (*(iter))->down();
    }
}

bool App_controller::can_left()
{
    vector<Block*>::iterator iter = current.piece.begin();
    for (iter = current.piece.begin(); iter != current.piece.end(); ++iter) {
        if ((*(iter))->get_x() - 1 < 0) {
            return false;
        }
        if (!map.is_empty((*(iter))->get_x() - 1, (*(iter))->get_y()))
            return false;
    }
    return true;
}

bool App_controller::can_right()
{
    vector<Block*>::iterator iter = current.piece.begin();
    for (iter = current.piece.begin(); iter != current.piece.end(); ++iter) {
        if ((*(iter))->get_x() + 1 >= WIDTH) {
            return false;
        }
        if (!map.is_empty((*(iter))->get_x() + 1, (*(iter))->get_y()))
            return false;
    }
    return true;
}

bool App_controller::can_down()
{
    vector<Block*>::iterator iter = current.piece.begin();
    for (iter = current.piece.begin(); iter != current.piece.end(); ++iter) {
        if ((*(iter))->get_y() - 1 < 0) {
            return false;
        }
        if (!map.is_empty((*(iter))->get_x(), (*(iter))->get_y() - 1))
            return false;
    }
    return true;
}

bool App_controller::can_rotate()
{
    switch (current.get_type())
    {
    case FOLD :
        switch (current.get_num_rot())
        {
        case 0:
            return (map.getCurrent(current.piece[0]->get_x() - 1, current.piece[0]->get_y())->get_color() == EMPTY);
        case 1:
            return (map.getCurrent(current.piece[0]->get_x(), current.piece[0]->get_y() - 1)->get_color() == EMPTY);
        case 2:
            return (map.getCurrent(current.piece[0]->get_x() + 1, current.piece[0]->get_y())->get_color() == EMPTY);
        case 3:
            return (map.getCurrent(current.piece[0]->get_x(), current.piece[0]->get_y() + 1)->get_color() == EMPTY);
        default:
            return false;
        }

    case TREE :
        switch (current.get_num_rot())
        {
        case 0:
        case 2:
            return (current.piece[1]->get_x() - 1 >= 0 && current.piece[1]->get_x() + 1 < WIDTH
                && map.getCurrent(current.piece[1]->get_x() + 1, current.piece[1]->get_y())->get_color() == EMPTY
                && map.getCurrent(current.piece[1]->get_x() - 1, current.piece[1]->get_y())->get_color() == EMPTY);

        case 1:
        case 3:
            return (current.piece[1]->get_y() + - 1 > 0
                && map.getCurrent(current.piece[1]->get_x(), current.piece[1]->get_y() + 1)->get_color() == EMPTY
                && map.getCurrent(current.piece[1]->get_x(), current.piece[1]->get_y() - 1)->get_color() == EMPTY);

        default:
            return false;
        }

    case CROSS :
        return true;

    default:
        break;
    }

    return false;
}

bool App_controller::search_left(Block* block, int color)
{
    return (block->get_x() - 1 >= 0
        && map.getCurrent(block->get_x() - 1, block->get_y())->get_color() == color);
}

bool App_controller::search_right(Block* block, int color)
{
    return (block->get_x() + 1 < WIDTH
        && map.getCurrent(block->get_x() + 1, block->get_y())->get_color() == color);
}

bool App_controller::search_below(Block* block, int color)
{
    return (block->get_y() - 1 >= 0
        && map.getCurrent(block->get_x(), block->get_y() - 1)->get_color() == color);
}

bool App_controller::search_above(Block* block, int color)
{
    return (block->get_y() + 1 < HEIGHT
        && map.getCurrent(block->get_x(), block->get_y() + 1)->get_color() == color);
}
        
bool App_controller::check_current_end()
{
    if (!can_down()) {
        down_all();
        down_all();
        down_all();
        add_piece();

        
        if (explode())
        {
            puyo_drop();
            map.setScore(map.getScore() + 1);
        }

        if (map.full_end_position()) {
            print_end();
            return true;
        }

        else {
            
            current = piece_maker.make_piece();
            return false;
        }
    }
    return false;
}

void App_controller::puyo_drop()
{
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (map.getCurrent(i, j)->get_color() == EMPTY)
                continue;
            else {
                for (int k = j - 1; k >= 0; k--) {
                    if (k == 0 && map.getCurrent(i, k)->get_color() == EMPTY) {
                        int temp = map.getCurrent(i, j)->get_color();
                        map.getCurrent(i, j)->set_color(EMPTY);
                        map.getCurrent(i, k)->set_color(temp);
                    }
                    if (map.getCurrent(i, k)->get_color() == EMPTY)
                        continue;
                    else if (map.getCurrent(i, k)->get_color() != EMPTY) {
                        int temp = map.getCurrent(i, j)->get_color();
                        map.getCurrent(i, j)->set_color(EMPTY);
                        map.getCurrent(i, k + 1)->set_color(temp);
                        break;
                    }
                }
            }
        }
    }
}

bool App_controller::explode()
{
    bool pop = false;
    vector<Block*>::iterator iter;
    vector<Block*> blk_vector;
    queue<Block*> blk_queue;
    for (int color = 2; color < 5; color++) {
        bool search[WIDTH][HEIGHT] = { false };
        for (int x = 0; x < WIDTH; x++) {
            for (int y = 0; y < HEIGHT; y++) {
                if (map.getCurrent(x, y)->get_color() == color && search[x][y] == false) {
                    blk_queue.push(map.getCurrent(x, y));
                    search[x][y] = true;
                    while (!blk_queue.empty()) {

                        Block* new_block = blk_queue.front();

                        if (search_right(new_block, color)
                            && search[new_block->get_x() + 1][new_block->get_y()] == false) {

                            blk_queue.push(map.getCurrent(new_block->get_x() + 1, new_block->get_y()));
                            search[new_block->get_x() + 1][new_block->get_y()] = true;
                        }

                        if (search_left(new_block, color)
                            && search[new_block->get_x() - 1][new_block->get_y()] == false) {

                            blk_queue.push(map.getCurrent(new_block->get_x() - 1, new_block->get_y()));
                            search[new_block->get_x() - 1][new_block->get_y()] = true;
                        }

                        if (search_above(new_block, color)
                            && search[new_block->get_x()][new_block->get_y() + 1] == false) {

                            blk_queue.push(map.getCurrent(new_block->get_x(), new_block->get_y() + 1));
                            search[new_block->get_x()][new_block->get_y() + 1] = true;
                        }

                        if (search_below(new_block, color)
                            && search[new_block->get_x()][new_block->get_y() - 1] == false) {

                            blk_queue.push(map.getCurrent(new_block->get_x(), new_block->get_y() - 1));
                            search[new_block->get_x()][new_block->get_y() - 1] = true;
                        }

                        blk_vector.push_back(blk_queue.front());
                        blk_queue.pop();
                    }
                    if (blk_vector.size() >= 4) {
                        for (iter = blk_vector.begin(); iter != blk_vector.end(); ++iter) {
                            Block* to_search = (*(iter));
                            map.getCurrent((*(iter))->get_x(), (*(iter))->get_y())->set_color(EMPTY);
                            if (search_right(to_search, GREY))
                                map.getCurrent(to_search->get_x() + 1, to_search->get_y())->set_color(EMPTY);
                            if (search_left(to_search, GREY))
                                map.getCurrent(to_search->get_x() - 1, to_search->get_y())->set_color(EMPTY);
                            if (search_above(to_search, GREY))
                                map.getCurrent(to_search->get_x(), to_search->get_y() + 1)->set_color(EMPTY);
                            if (search_below(to_search, GREY))
                                map.getCurrent(to_search->get_x(), to_search->get_y() - 1)->set_color(EMPTY);
                        }
                        pop = true;
                        blk_vector.clear();
                    }
                    else {
                        blk_vector.clear();
                    }
                }
                else {
                    search[x][y] = true;
                }
            }
        }

    }
    return pop;
}


void App_controller::print_end()
{
    system("clear");
    print_score();

    cout <<  "========================" << endl;
    for (int j = HEIGHT - 1; j >= 6; j--) {
        cout << "||  ";
        for (int i = 0; i < WIDTH; i++) {
            cout << " " << "  ";
        }
        cout << "||" << endl;
    }
    cout << "||  G A M E  O V E R  ||" << "  " << endl;
    for (int j = 4; j >= 0; j--) {
        cout << "||  ";
        for (int i = 0; i < WIDTH; i++) {
            cout << "   ";
        }
        cout << "||" << endl;
    }
    cout <<  "========================" << endl;
}


void App_controller::input()
{
    cout << "명령을 입력하세요 : ";
    char input;
    cin >> input;
    handle_command(input);
}



void App_controller::handle_command(char command)
{
    switch (command) {
    case 'a':
        cout << "left" << endl;
        if (can_left())
            current.left();
        break;
    case 's':
        cout << "down" << endl;
        if (can_down())
            current.down();
        break;
    case 'd':
        cout << "right" << endl;
        if (can_right())
            current.right();
        break;
    case 'x':
        cout << "down_all" << endl;
        if (can_down())
            down_all();
        break;
    case 'e':
        cout << "rotate" << endl;
        if (can_rotate()) {
            current.rotate();
            cout << current.get_num_rot();
        }
        break;
    default:
        cout << "error command" << endl;
        input();
    }
}

void App_controller::run()
{
    
    while (1) {
        system("clear");
        if (check_current_end()) {
            break;
        }
        show_map();
        input();
    }
}
