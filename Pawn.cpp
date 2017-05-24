#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

#include <iostream>
#include <cmath>

using namespace std;

Pawn::Pawn()
{
    value = 1;
    moved = false;
    symbol = 'P';
}

int Pawn::getXPosition() 
{
    return x;
}

int Pawn::getYPosition() 
{
    return y;
}
bool Pawn::isMoveValid(int col, int row, Tile board[8][8])
{
    cout << "Checking pawn" << x << y << endl;
    if(board[row][col].isOccupied())
    {
	return (canEat(col, row, board));
    }
    else
    {
	return (canMove(col, row, board));
    }
}

bool Pawn::canMove(int col, int row, Tile board[8][8])
{
    if(y - row == 0)
    {
	return false;
    }
    int deltaY;
    deltaY = y - row;
    if(color == 'W' && col == x)
    {
	if(!moved)
	{
	    moved = true;
	    return(deltaY == 1|| deltaY == 2);
	}
	else
	{
	    return(deltaY == 1);
	}
    }
    else if(color == 'B' && col == x)
    {
	if(!moved)
	{
	    moved = true;
	    return(deltaY == -1 || deltaY == -2);
	}
	else
	{
	    return(deltaY == -1);
	}
    }
    else
    {
	return false;
    }
}

bool Pawn::canEat(int col, int row, Tile board[8][8])
{
    if(col - x == 0 || row - y == 0)
    {
	return false;
    }
    float deltaX = abs(col -x);
    float deltaY = abs(row-y);
    if(deltaX == 0 || deltaY == 0)
    {
	return false;
    }
    float slope = deltaY/deltaX;
    if(slope == 1.0)
    { 
	if(board[row][col].isOccupied());
	{
	    if(color == 'W')
	    {
		if(row - y == -1)
		{
		    return(board[row][col].occupier->getColor()== 'B'); //if piece is white and if enemy color is black 
		}
		else
		{
		    return false;
		}
	    }
	    if(color == 'B')
	    {
		if(row - y == 1)
		{
		    return (board[row][col].occupier->getColor() == 'W'); //if piece is black and if enemy color is white
		}
		else
		{
		    return false;
		}
	    }
	}
    }
    else
    {
	return false;
    }
}

bool Pawn::hasMoved()
{
    return moved;
}

void Pawn::setMoved()
{
    moved = true;
}

void Pawn::promotion(int col, int row, Tile board[8][8])
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
    (chosen_piece != 'Q' || chosen_piece != 'R' || chosen_piece != 'B' 
	    || chosen_piece != 'R');

    cout << "Changing P to " << chosen_piece << endl;

    {
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
    }
}
