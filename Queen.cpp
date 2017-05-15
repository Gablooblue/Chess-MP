#include "Queen.h"
#include <cmath>
#include <iostream>

using namespace std;

Queen::Queen()
{
    value = 9;
}

int Queen::getYPosition()
{
    return y;
}

int Queen::getXPosition()
{
    return x;
}

bool Queen::checkDiagonal(int col, int row, Tile board[8][8])
{
    int rise, run;
    rise = y - row;
    run = x - col;
    if(run == 0)
    {
	return false;
    }
    return(abs(rise/run) == 1);
}

bool Queen::checkVertical(int col, Tile board[8][8])
{
    return(x == col);
}

bool Queen::checkHorizontal(int row, Tile board[8][8])
{
    return(y == row);
}

bool Queen::isMoveValid(int col,int row, Tile board[8][8])
{
    return (checkDiagonal(col, row, board) && checkHorizontal(row, board) && checkVertical(col, board));
}
