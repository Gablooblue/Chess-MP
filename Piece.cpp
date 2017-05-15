#include "Piece.h"
#include "Tile.h"
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

void Piece::setColor(char c)
{
    color = c;
}

char Piece::getColor()
{
    return color;
}

void Piece::deletePiece()
{
    x = -1;
    y = -1;
}

