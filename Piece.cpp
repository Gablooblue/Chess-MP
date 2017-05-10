#include "piece.h"
#include <iostream>

using namespace std;

Piece::Piece()
{
    x = 0; 
    y = 0;
}

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


