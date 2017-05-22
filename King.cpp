#include "King.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King()
{
    value = 1000000;
    symbol = 'K';
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
    deltaX = abs(col - x);
    deltaY = abs(row - y);

    return(deltaX == 1 || deltaX == 0 && deltaY == 1|| deltaY == 0);

}
