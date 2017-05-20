#include "Pawn.h"

#include <iostream>
#include <cmath>

using namespace std;

Pawn::Pawn()
{
    value = 1;
    moved = false;
    symbol = 'P';
}

int Pawn::getXPosition() 
{
    return x;
}

int Pawn::getYPosition() 
{
    return y;
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
	if(!hasMoved())
	{
	    return(row == y + 1 || row == y + 2 && col == x);
	}
	else
	{
	    return(row == y + 1 && col == x);
	}
    }
    else if(color == 'B')
    {
	if(!hasMoved())
	{
	    return(row == y - 1 || row == y - 2 && col == x);
	}
	else
	{
	    return(row == y - 1 && col == x);
	}

    }
}

bool Pawn::canEat(int col, int row, Tile board[8][8])
{
    int deltaX = abs(col -x);
    int deltaY = abs(row-y);
    if(deltaX == 0)
    {
	return false;
    }
    int slope = deltaY/deltaX;
    if(slope == 1)
    { 
	if(board[row][col].isOccupied());
	{
	    if(color == 'W')
	    {
		if(row - y == 1)
		{
		    if(board[row][col].occupier->getColor()== 'B') //if piece is white and if enemy color is black 
		    {
			return true;
		    }
		}
	    }
	    if(color == 'B')
	    {
		if(row - y == -1)
		{
		    if(board[row][col].occupier->getColor() == 'W') //if piece is black and if enemy color is white
		    {
			return true;
		    }
		}
	    }
	    else
	    {
		return false;
	    }
	}
    }
}

bool Pawn::hasMoved()
{
    return moved;
}

bool Pawn::setMoved()
{
    moved == true;
}
