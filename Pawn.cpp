#include "Pawn.h"
#include <iostream>

using namespace std;

Pawn::Pawn()
{

}

bool Pawn::isMoveValid(int col, int row, Tile board[8][8])
{
    canMove(col, row, board);
    canEat(col, row, board);
}

bool Pawn::canMove(int col, int row, Tile board[8][8])
{
    if(color == 'W')
    {
	if(row == y + 1 && col == x)
	{
	    return true;
	}
    }
    else if(color == 'B')
    {
	if(row == y - 1 && col == x)
	{
	    return true;
	}
    }
}
