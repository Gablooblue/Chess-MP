#include "Queen.h"
#include <iostream>

using namespace std;

Queen::Queen()
{
    x = 0;
    y = 0;
}

int Queen::getYPosition()
{
    return y;
}

int Queen::getXPosition()
{
    return x;
}

bool Queen::checkDiagonal(int col, int row, int board[8][8])
{
    int rise, run;
    rise = y - row;
    run = x - col;
    return(rise/run == 1);
}

bool Queen::checkVertical(int col, int board[8][8])
{
    return(x == col);
}

bool Queen::checkHorizontal(int row, int board[8][8])
{
    return(y == row);
}

bool Queen::isMoveValid(int col,int row, int board[8][8])
{
    return (checkDiagonal(col, row, board) && checkHorizontal(row, board) && checkVertical(col, board));
}
