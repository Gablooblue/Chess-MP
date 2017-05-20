#include "Queen.h"
#include <cmath>
#include <iostream>

using namespace std;

Queen::Queen()
{
    value = 9;
    symbol = 'Q';

}

bool Queen::checkDiagonal(int col, int row, Tile board[8][8])
{
    float rise, run;
    rise = y - row;
    run = x - col;
    float slope = abs(rise/run);
    if(run == 0)
    {
	return false;
    }
    return(slope == 1.0);
}

bool Queen::checkVertical(int col, int row, Tile board[8][8])
{
    /*for(int i = 0; i < abs(row - y); i++)
    {
	if(board[y+ i][col].isOccupied() && board[row + i][col].occupier->getColor() == color)
	{
	    return false;
	}
    }*/
    if(row < y)
    {
	for(int i = 1; i < y; i++)
	{
	    if(board[row + i][col].isOccupied())
	    {
		return false;
	    }
	}
    }
    else if(row > y)
    {
	for(int i = 1; i < row; i++ )
	{
	    if(board[y + i][col].isOccupied())
	    {
		return false;
	    }
	}
    }
    return(x == col);
}

bool Queen::checkHorizontal(int row, int col, Tile board[8][8])
{
    return(y == row);
}

bool Queen::isMoveValid(int col,int row, Tile board[8][8])
{
    return (checkDiagonal(col, row, board) || checkHorizontal(col, row, board) || checkVertical(col, row, board));
}
