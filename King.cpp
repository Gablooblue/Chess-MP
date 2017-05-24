#include "King.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King()
{
    value = 1000000;
    symbol = 'K';
    moved = false;
}

bool King::isCheckmated(Tile board[8][8])
{
    //TODO
}

bool King::isInCheck(Tile board[8][8])
{
    /*for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    if(board[i][j].occupier != NULL 
		    && board[i][j].occupier->getColor() != color)
	    {
		if(board[i][j].occupier->isMoveValid(x, y, board))
		{
		    cout << "King can be attacked on " << x << y << endl;
		    return true; 
		}
	    }
	}
    }*/
}

bool King::isMoveValid(int col, int row, Tile board[8][8])
{
    int deltaX, deltaY;

    deltaX = col - x != 0 ? abs(col -x) : 0;
    deltaY = row - y != 0 ? abs(row -y) : 0;

    if (deltaX == 0 && deltaY == 0  )
	return false;
    if(deltaY > 1 || deltaX > 1)
	return false;
    
    if(deltaX == 1 || deltaX == 0 && deltaY == 1|| deltaY == 0)
    {
	if(board[row][col].isOccupied() && board[row][col].occupier->getColor() == color)
	{
	    return false;
	}	
	else
	{
	    if(!moved)
	    {
		moved = true;
	    }
	    return true;
	}
    }
   
    else
    {
	return false;
    }

}
