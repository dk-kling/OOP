#include "Piece_maker.h"

Piece_maker::Piece_maker()
{
}

Piece Piece_maker::make_piece()
{
	int type = (rand() % 3) + 1;
	Piece *piece;

	switch (type)
	{
	case FOLD:
		piece = new Fold();
		piece->set_type(FOLD);
		break;

	case TREE:
		piece = new Tree(); 
		piece->set_type(TREE);
		break;

	case CROSS:
		piece = new Cross();
		piece->set_type(CROSS);
		break;

	default:
		break;
	}
	return *piece;
}

