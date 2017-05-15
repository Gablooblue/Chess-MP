#ifndef ROOK_H 
#define ROOK_H

#include "Queen.h"
using namespace std;

class Rook: public Queen
{
    public:
	Rook();
	bool isMoveValid(int col, int row, Tile board[8][8]);
};

#endif
