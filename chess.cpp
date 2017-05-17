#include "Tile.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"

#include <iostream>

using namespace std;

void menu();
void start();
void setupBoard(Tile board[8][8]);
void printBoard(Tile board[8][8]);

int main()
{
    menu();
}

void menu()
{
    int input;
    do
    {
	cout << "[1] Start"
	     << "[4] Quit";
	switch (input)
	{
	    case 1: start();
		    break;
	    case 4: break;
		    break;
	    default: cout << "Choose a valid option";
	}
    }
    while(input > 4 || input < 1);
}

void start()
{
    Tile board[8][8];
    setupBoard(board);
    printBoard(board);

}

void setupBoard(Tile board[8][8])
{
    int i, j;
    char c;
    for(i = 0; i < 8; i++)
    {
	for(j = 0; j < 8; j++)
	{
	    board[i][j].setCoordinates(i, j);
	    if(i == 3 && j == 3 || i == 3 && j == 4 || i == 4 && j == 3 || 
		i == 4 && j ==4)
	    {
		board[i][j].setValue(2);
	    }
	}
    }
    //Place Pawns
    for(i = 0 , j = 1; i < 8; i++)
    {
	Pawn* newPawn = new Pawn;
	newPawn->setColor('B');
	board[i][j].setPiece(newPawn);
    }
    for(i = 0, j = 7; i < 8; i++)
    {
	Pawn* newPawn = new Pawn;
	newPawn->setColor('W');
	board[i][j].setPiece(newPawn);
    }
    //Place Queens
    Queen* newBQueen = new Queen;
    Queen* newWQueen = new Queen;
    newWQueen->setColor('W');
    newBQueen->setColor('B');
    board[4][0].setPiece(newBQueen);
    board[4][7].setPiece(newWQueen);
    //Place Kings
    King* newBKing = new King;
    King* newWKing = new King;
    newBKing->setColor('B');
    newWKing->setColor('W');
    board[3][0].setPiece(newBKing);
    board[3][7].setPiece(newWKing);
    //Place Bishops
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 2; j < 6;j+=3)
	{
	    Bishop* newBishop = new Bishop;
	    newBishop->setColor(c);
	    board[i][j].setPiece(newBishop);
	}
	c = 'W';
    }
    //Place Rooks
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 0; j < 8;j+=7)
	{
	    Rook* newRook = new Rook;
	    newRook->setColor(c);
	    board[i][j].setPiece(newRook);
	}
	c = 'W';
    }
    //Place Knights
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 1; j < 7;j+=5)
	{
	    Knight* newKnight = new Knight;
	    newKnight->setColor(c);
	    board[i][j].setPiece(newKnight);
	}
	c = 'W';
    }
}

void printBoard(Tile board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    cout << board[i][j].occupier->getSymbol();
	}
    }
}
