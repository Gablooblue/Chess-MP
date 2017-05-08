#include "queen.h"
#include <iostream>

using namespace std;

int Queen::getYPosition()
{
    return y;
}

int Queen::getXPosition()
{
    return x;
}

bool Queen::checkDiagonal(int x, int y, int board[8][8])
{
    int i, j;
    //checking up-left
    for(i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
    }

    //checking down-right
    for(i = x, j = y; i < 8 && j < 8; i++, j++)
    {
    }

    //checking down-left
    for(i = x, j = y; i >= 0 && j < 8; i--, j++)
    {
    }

    //checking up-right
    for(i = x, j = y; i < 8 && j >= 0; i++, j--)
    {
    }
}

bool Queen::checkVertical(int x, int board[8][8])
{
    for(int i = 0; i < 8; i++)
    {

    }
}

bool Queen::checkHorizontal(int board[8][8])
{
    for(int j = 0; j < 8; j++)
    {

    }
}

bool Queen::isMoveValid(int x,int y, int board[8][8])
{
    return (checkDiagonal(x, y, board) && checkHorizontal(x, y, board) && checkVertical(x, y, board));
}
