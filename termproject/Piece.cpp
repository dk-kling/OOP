#include "Piece.h"

Piece::Piece()
{
}

int Piece::get_type()
{
	return type;
}

void Piece::set_type(int _type)
{
	this->type = _type;
}

void Piece::set_piece(vector<Block*> piece)
{
	this->piece = piece;
}

vector<Block*> Piece::get_piece()
{
	return piece;
}

void Piece::down()
{
	vector<Block*>::iterator iter;
	for (iter = piece.begin(); iter != piece.end(); ++iter) {
		(*(iter))->down();
	}
}

void Piece::left()
{
	vector<Block*>::iterator iter = piece.begin();
	for (iter = piece.begin(); iter != piece.end(); ++iter) {
		(*(iter))->left();
	}
}

void Piece::right()
{
	vector<Block*>::iterator iter = piece.begin();
	for (iter = piece.begin(); iter != piece.end(); ++iter) {
		(*(iter))->right();
	}
}

void Piece::rotate()
{
	int temp = 0;
	switch (get_type())
	{
	case FOLD:
		switch (get_num_rot())
		{
		case 0: {
			piece[0]->set_x(piece[0]->get_x() - 1);
			piece[1]->set_y(piece[1]->get_y() + 1);
			piece[2]->set_x(piece[2]->get_x() + 1);
			set_num_rot(1);
			return;
		}
		case 1: {
			piece[0]->set_y(piece[0]->get_y() - 1);
			piece[1]->set_x(piece[1]->get_x() - 1);
			piece[2]->set_y(piece[2]->get_y() + 1);
			set_num_rot(2);
			return;
		}
		case 2: {
			piece[0]->set_x(piece[0]->get_x() + 1);
			piece[1]->set_y(piece[1]->get_y() - 1);
			piece[2]->set_x(piece[2]->get_x() - 1);
			set_num_rot(3);
			return;
		}
		case 3: {
			piece[0]->set_y(piece[0]->get_y() + 1);
			piece[1]->set_x(piece[1]->get_x() + 1);
			piece[2]->set_y(piece[2]->get_y() - 1);
			set_num_rot(0);
			return;
		}
		default:
			break;
		}

	case TREE:
		switch (get_num_rot())
		{
		case 0: {
			piece[0]->set_x(piece[1]->get_x() + 1);
			piece[0]->set_y(piece[1]->get_y());
			piece[2]->set_x(piece[1]->get_x() - 1);
			piece[2]->set_y(piece[1]->get_y());
			set_num_rot(1);
			return;
		}
		case 1: {
			piece[0]->set_x(piece[1]->get_x());
			piece[0]->set_y(piece[1]->get_y() - 1);
			piece[2]->set_x(piece[1]->get_x());
			piece[2]->set_y(piece[1]->get_y() + 1);
			set_num_rot(2);
			return;
		}
		case 2: {
			piece[0]->set_x(piece[1]->get_x() - 1);
			piece[0]->set_y(piece[1]->get_y());
			piece[2]->set_x(piece[1]->get_x() + 1);
			piece[2]->set_y(piece[1]->get_y());
			set_num_rot(3);
			return;
		}
		case 3: {
			piece[0]->set_x(piece[1]->get_x());
			piece[0]->set_y(piece[1]->get_y() + 1);
			piece[2]->set_x(piece[1]->get_x());
			piece[2]->set_y(piece[1]->get_y() - 1);
			set_num_rot(0);
			return;
		}
		default:
			break;
		}

	case CROSS: {
		int temp = piece[4]->get_color();
		piece[4]->set_color(piece[3]->get_color());
		piece[3]->set_color(piece[2]->get_color());
		piece[2]->set_color(piece[1]->get_color());
		piece[1]->set_color(temp);
		return;
	}

	default:
		break;
	}
}

int Piece::get_num_rot()
{
	return num_rot;
}

void Piece::set_num_rot(int num)
{
	this->num_rot = num;
}

