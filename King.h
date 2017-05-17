#ifndef	KING_H 
#define KING_H 

#include "Piece.h"
using namespace std;

class King: public Piece
{
    public:
	King();
	bool isInCheck(int col, int row, Tile board[8][8]);
	bool isMoveValid(int col, int row, Tile board[8][8]);
	bool isCheckmated(Tile board[8][8]);


};

#endif
