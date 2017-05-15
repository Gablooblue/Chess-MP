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
	newPawn->setXPosition(i);
	newPawn->setYPosition(j);
	newPawn->setColor('B');
    }
    for(i = 0, j = 7; i < 8; i++)
    {
	Pawn* newPawn = new Pawn;
	newPawn->setXPosition(i);
	newPawn->setYPosition(j);
	newPawn->setColor('W');
    }
    //Place Queens
    Queen* newBQueen = new Queen;
    Queen* newWQueen = new Queen;
    newBQueen->setXPosition(4);
    newWQueen->setXPosition(4);
    newBQueen->setYPosition(0);
    newWQueen->setXPosition(7);
    newWQueen->setColor('W');
    newBQueen->setColor('B');
    //Place Kings
    King* newBKing = new King;
    King* newWKing = new King;
    newBKing->setXPosition(3);
    newWKing->setXPosition(3);
    newBKing->setYPosition(0);
    newWKing->setYPosition(7);
    newBKing->setColor('B');
    newWKing->setColor('W');
    //Place Bishops
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 2; j < 6;j+=3)
	{
	    Bishop* newBishop = new Bishop;
	    newBishop->setXPosition(j);
	    newBishop->setYPosition(i);
	    newBishop->setColor(c);
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
	    newRook->setXPosition(j);
	    newRook->setYPosition(i);
	    newRook->setColor(c);
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
	    newKnight->setXPosition(j);
	    newKnight->setYPosition(i);
	    newKnight->setColor(c);
	}
	c = 'W';
    }
}

