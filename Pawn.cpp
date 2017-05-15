#include "Pawn.h"
#include <iostream>

using namespace std;

Pawn::Pawn()
{
    value = 1;
}

bool Pawn::isMoveValid(int col, int row, Tile board[8][8])
{
    return(canMove(col, row, board) ||
    canEat(col, row, board));
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

bool Pawn::canEat(int col, int row, Tile board[8][8])
{
    if(color == 'B') //and if enemy color is white
    {
	return true;
    }
    else if (color == 'W') // and if enemy color is black
    {
	return true;
    }
    else
    {
	return false;
    }
}
