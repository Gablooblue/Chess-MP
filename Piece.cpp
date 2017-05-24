#include "Piece.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Tile.h"
#include <iostream>
#include <stdio.h>

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
    char chosen_piece;
    do
    {
	cout << "Pawn can be promoted, what do you want to promote it to?"
	     << endl
	     << "Choices: Q, B, H, R" 
	     << endl;
	cin >> chosen_piece;
	chosen_piece = toupper(chosen_piece);
    }
    while
    (chosen_piece != 'Q' && chosen_piece != 'R' && chosen_piece != 'B' 
	    && chosen_piece != 'R');

    getchar();
    cout << "Changing P to " << chosen_piece << endl;

    char color = board[row][col].occupier->getColor();
    board[row][col].removePiece();
    if(chosen_piece == 'Q')
    {
	    Queen* newQueen = new Queen;
	    board[row][col].setPiece(newQueen);
    }
    else if(chosen_piece == 'H')
    {
	    Knight* newKnight = new Knight;
	    board[row][col].setPiece(newKnight);
    }
    else if(chosen_piece =='B')
    {
	    Bishop* newBishop = new Bishop;
	    board[row][col].setPiece(newBishop);
    }
    else if(chosen_piece == 'R')
    {
	    Rook* newRook = new Rook;
	    board[row][col].setPiece(newRook);
    }
    else	
    {
	    cout << "Error in character input" << endl;
	    Pawn* newPawn = new Pawn;
	    newPawn->setMoved();
	    board[row][col].setPiece(newPawn);
    }	
    board[row][col].occupier->setColor(color);

}

bool Piece::isInCheck(Tile board[8][8])
{
    cout << "Checking if king is in check" << endl;
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    if(board[i][j].isOccupied() 
		    && board[i][j].occupier->getColor() != color)
	    {
		if(board[i][j].occupier->isMoveValid(x, y, board))
		{
		    return true; 
		}
	    }
	}
    }
    return false;
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
	    cout << "Checking if " << board[y][x].occupier->getSymbol()<< x << y<<  " has moves" << endl;
	    if(board[y][x].occupier->isMoveValid(i, j, board))
	    {
		return true;
	    }
	}
    }
}

int Piece::getValue()
{
    return value;
}
