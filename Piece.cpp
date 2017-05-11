#include "Piece.h"
#include <iostream>

using namespace std;

void Piece::setXPosition(int coordinate)
{
    x = coordinate;
}

void Piece::setYPosition(int coordinate)
{
    y = coordinate;
}

void Piece::movePiece(int x, int y)
{
    setXPosition(x);
    setYPosition(y);
}

void Piece::getYPosition()
{
    return y;
}

void Piece::getXPosition()
{
    return x;
}

void Piece::setColor(char c)
{
    color = c;
}

void Piece::getColor()
{
    return color;
}

