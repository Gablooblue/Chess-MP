#ifndef PAWN_H 
#define PAWH_H 

#include "Piece.h"
#include "Tile.h"
using namespace std;


class Pawn: public Piece
{
    public: 
	Pawn();
	int getXPosition();
	int getYPosition();
	bool isMoveValid(int col, int row, Tile board[8][8]);
	bool canEat(int col, int row, Tile board[8][8]);
	bool canMove(int col, int row, Tile board[8][8]);
	bool hasMoved();
	bool setMoved();
    private: 
	bool moved;
};

#endif
