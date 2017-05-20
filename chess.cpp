#include "Tile.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void menu();
void start();
void setupBoard(Tile board[8][8]);
void printBoard(Tile board[8][8]);
bool movePiece(int ini_col,int ini_row, int fin_col,int fin_row, Tile board[8][8]);
void askForMove(Tile board[8][8]);
int translate(char input);

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
	     << "[4] Quit"
	     << endl;
	cin >> input;
	getchar();
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
    do
    {
	askForMove(board);
	printBoard(board);
    }
    while(true);
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
    for(i = 1 , j = 0; j < 8; j++)
    {
	Pawn* newPawn = new Pawn;
	newPawn->setColor('B');
	board[i][j].setPiece(newPawn);
    }
    for(i = 6, j = 0; j < 8; j++)
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
    board[0][4].setPiece(newBQueen);
    board[7][4].setPiece(newWQueen);
    //Place Kings
    King* newBKing = new King;
    King* newWKing = new King;
    newBKing->setColor('B');
    newWKing->setColor('W');
    board[0][3].setPiece(newBKing);
    board[7][3].setPiece(newWKing);
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
    cout << " 1 2 3 4 5 6 7 8" << endl;
    cout << "-----------------" << endl;
    for(int i = 0; i < 8; i++)
    {
	cout << '|';
	for(int j = 0; j < 8; j++)
	{
	    if(board[i][j].occupier != NULL)
		cout << board[i][j].occupier->getSymbol();
	    else
		cout << ' ';
	    cout << '|';
	}
	cout << endl;
	cout << "-----------------";
	cout << endl;

    }
}

bool movePiece(int ini_col, int ini_row ,int fin_col ,int fin_row, Tile board[8][8])
{
    cout << "Moving " << ini_col << ini_row << "to" << fin_col << fin_row;
    if(board[ini_row][ini_col].occupier->isMoveValid(fin_col, fin_row, board)) 
    {
	if(board[fin_row][fin_col].occupier != NULL)
	{
	    board[fin_row][fin_col].removePiece();
	    cout << "Piece eaten" << endl;
	}
	board[fin_row][fin_col].setPiece(board[ini_row][ini_col].occupier);
	board[ini_row][ini_col].removePiece();
    }
    else 
    {
	return false;
    }
}

void askForMove(Tile board[8][8])
{
    int ini_x, ini_y, fin_x, fin_y;
    string select, place;
    cout << "Pick a piece to move: ";
    getline(cin, select);
    ini_x = translate(select[0]);
    ini_y = translate(select[1]);
    if(board[ini_y][ini_x].occupier == NULL)
    {
	cout << "No piece in the space" << endl;
	return;
    }
    cout << "Pick where to move the piece: ";
    getline(cin, place);
    fin_x = translate(place[0]);
    fin_y = translate(place[1]);
    movePiece(ini_y, ini_x, fin_y, fin_x, board);
}

int translate(char input)
{
    int ascii_value;
    
    ascii_value = input - '0' - 1;
    if(ascii_value > 10)
    {
	ascii_value = tolower(input) - '0' - 49;
    }
    return ascii_value;
}
