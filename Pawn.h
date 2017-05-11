#include "Piece.h"

using namespace std;

class Pawn: public Piece
{
    public: 
	Pawn();
	bool isMoveValid(int col, int row, Tile board[8][8]);
	bool canEat(int col, int row, Tile board[8][8]);
	bool canMove(int col, int row, Tile board[8][8]);
};
