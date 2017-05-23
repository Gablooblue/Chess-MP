#include "Piece.h"
#include "Tile.h"
#include <iostream>

using namespace std;

Piece::Piece()
{
    symbol = ' ';
}
int Piece::getXPosition()
{
    return x;
}

int Piece::getYPosition()
{
    return y;
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

char Piece::getSymbol()
{
    return symbol;
}

void Piece::setCoordinates(int col, int row)
{
    x = col;
    y = row;
}


void Piece::promotion(int col, int row, Tile board[8][8])
{

}

bool Piece::isInCheck(Tile board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    if(board[i][j].occupier != NULL 
		    && board[i][j].occupier->getColor() != color)
	    {
		if(board[i][j].occupier->isMoveValid(x, y, board))
		{
		    return true; 
		}
	    }
	}
    }
}

void Piece::setMoved()
{
    moved = true;
}

bool Piece::hasMoved()
{
    return moved;
}

bool Piece::hasMoves(Tile board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    if(board[y][x].occupier->isMoveValid(i, j, board))
	    {
		return true;
	    }
	}
    }
}
