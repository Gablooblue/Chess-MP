#include "Piece.h"
#include "Tile.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
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
    x = col;
    y = row;
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

void Tile::makePiece(char piece, char color, Tile board[8][8])
{
    if(piece == 'Q')
    {
	Queen* newQueen = new Queen;
	if(color == 'W')
	{
	    newQueen->setColor('W');
	}
	else
	{
	    newQueen->setColor('B') ;
	}
	board[y][x].setPiece(newQueen);
    }
    else if(piece == 'P')
    {
	Pawn* newPawn= new Pawn;
	if(color == 'W')
	{
	    newPawn->setColor('W');
	}
	else
	{
	    newPawn->setColor('B') ;
	}
	board[y][x].setPiece(newPawn);
    }
    else if(piece == 'R')
    {
	Rook* newRook = new Rook;
	if(color == 'W')
	{
	    newRook->setColor('W');
	}
	else
	{
	    newRook->setColor('B') ;
	}
	board[y][x].setPiece(newRook);
    }
    else if(piece == 'B')
    {
	Bishop* newBishop= new Bishop;
	if(color == 'W')
	{
	    newBishop->setColor('W');
	}
	else
	{
	    newBishop->setColor('B') ;
	}
	board[y][x].setPiece(newBishop);
    }
    else if(piece == 'H')
    {
	Knight* newKnight= new Knight;
	if(color == 'W')
	{
	    newKnight->setColor('W');
	}
	else
	{
	    newKnight->setColor('B') ;
	}
	board[y][x].setPiece(newKnight);
    }
    else if(piece == 'K')
    {
	King* newKing= new King;
	if(color == 'W')
	{
	    newKing->setColor('W');
	}
	else
	{
	    newKing->setColor('B') ;
	}
	board[y][x].setPiece(newKing);
    }
}
