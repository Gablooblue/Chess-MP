#ifndef BISHOP_H 
#define BISHOP_H

#include "Queen.h"
using namespace std;

class Bishop: public Queen
{
    public: 
	Bishop();
	bool isMoveValid(int col, int row, Tile board[8][8]);
};

#endif
