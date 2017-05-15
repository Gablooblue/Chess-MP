#ifndef QUEEN_H 
#define QUEEN_H 

#include "Piece.h"
using namespace std;

class Queen: public Piece
{
    public: 
	Queen();
	int getYPosition();
	int getXPosition();
	bool checkDiagonal(int x, int y, Tile board[8][8]);
	bool checkHorizontal(int y, Tile board[8][8]);
	bool checkVertical(int x, Tile board[8][8]);
	bool isMoveValid(int x, int y, Tile board[8][8]);
};

#endif
