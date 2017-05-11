#include "Piece.h"

using namespace std;

class Knight: public Piece
{
    public:
	Knight();
	bool isMoveValid(int col, int row, Tile board[8][8]);
	bool checkMove(int col, int row, Tile board[8][8]);
};
