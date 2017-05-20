#include "Piece.h"
#include "Tile.h"
#include <iostream>

using namespace std;

Tile::Tile()
{
    occupier = NULL;
    value = 0;
}

void Tile::setPiece(Piece* p)
{
    occupier = p;
    occupier->setCoordinates(x, y);
}

void Tile::removePiece()
{
    occupier = NULL;
}

void Tile::setCoordinates(int col, int row)
{
    y = col;
    x = row;
}

int Tile::getXCoordinates()
{
    return x;
}
 
int Tile::getYCoordinates()
{
    return y;
}

void Tile::setValue(int val)
{
    value = val;
}

int Tile::getValue()
{
    return value;
}

bool Tile::isOccupied()
{
    return(occupier != NULL);
}

