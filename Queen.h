#ifndef QUEEN_H 
#define QUEEN_H 

#include "Piece.h"
#include "Tile.h"
using namespace std;

class Queen: public Piece
{
    public: 
	Queen();
	bool checkDiagonal(int col, int row, Tile board[8][8]);
	bool checkHorizontal(int col, int row, Tile board[8][8]);
	bool checkVertical(int col, int row, Tile board[8][8]);
	bool isMoveValid(int col, int row, Tile board[8][8]);
};

#endif
