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
    if(board[row][col].isOccupied())
    {
	return canEat(col, row, board);
    }
    else
    {
	return canMove(col, row, board);
    }
}

bool Pawn::canMove(int col, int row, Tile board[8][8])
{
    cout << "color: " << color << endl;
    int deltaY = 0;
    deltaY = abs(y - row );
    cout << "deltaY: " <<  deltaY << endl;
    if(color == 'W' && col == x)
    {
	if(!moved)
	{
	    moved = true;
	    return(deltaY == 1|| deltaY == 2);
	}
	else
	{
	    return(deltaY == 1);
	}
    }
    else if(color == 'B' && col == x)
    {
	if(!moved)
	{
	    moved = true;
	    return(deltaY == 1 || deltaY == 2);
	}
	else
	{
	    return(deltaY == 1);
	}
    }
}

bool Pawn::canEat(int col, int row, Tile board[8][8])
{
    float deltaX = abs(col -x);
    cout << "deltax: " << deltaX << endl;
    float deltaY = abs(row-y);
    cout << "deltay: " << deltaY << endl;
    if(deltaX == 0)
    {
	return false;
    }
    float slope = deltaY/deltaX;
    cout << "Slope: " << slope << endl;
    if(slope == 1.0)
    { 
	if(board[row][col].isOccupied());
	{
	    if(color == 'W')
	    {
		if(row - y == -1)
		{
		    return(board[row][col].occupier->getColor()== 'B'); //if piece is white and if enemy color is black 
		}
		else
		{
		    return false;
		}
	    }
	    if(color == 'B')
	    {
		if(row - y == 1)
		{
		    return (board[row][col].occupier->getColor() == 'W'); //if piece is black and if enemy color is white
		}
		else
		{
		    return false;
		}
	    }
	}
    }
    else
    {
	return false;
    }
}

bool Pawn::hasMoved()
{
    return moved;
}

bool Pawn::setMoved()
{
    moved = true;
}
