#include "Piece.h"
#include "Tile.h"
#include <iostream>

using namespace std;

Tile::Tile()
{
    occupier = NULL;
}

void Tile::setPiece(Piece* p)
{
    occupier = p;
}

void Tile::removePiece()
{
    occupier = NULL;
}
