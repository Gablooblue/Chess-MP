#include "King.h"
#include <iostream>
#include <cmath>

using namespace std;

King::King()
{
    value = 1000000;
}

int King::getXPosition()
{
    return x;
}
int King::getYPosition()
{
    return y;
}
bool King::isInCheck(int col, int row, Tile board[8][8])
{
    //Do this later 
}

bool King::isMoveValid(int col, int row, Tile board[8][8])
{
    int deltaX, deltaY;
    deltaX = abs(col - x);
    deltaY = abs(row - y);

    return(deltaX == 1 || deltaX == 0 && deltaY == 1|| deltaY == 0);

}
