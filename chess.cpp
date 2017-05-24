#include "Tile.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define LIMIT 3

void menu();
void start();
void setupBoard(Tile board[8][8]);
void printBoard(Tile board[8][8]);
bool movePiece(int ini_col,int ini_row, int fin_col,int fin_row, Tile board[8][8]);
bool askForMove(int turn, Tile board[8][8]);
int translate(char input);
void checkForPromotion(int col, int row, Tile board[8][8]);
bool isKingInCheck(char color, Tile board[8][8]);
void undo(int ini_col, int ini_row, int fin_col, int fin_row, bool ate, Piece* eaten, Tile board[8][8]);
bool isCheckmated(char color, Tile board[8][8]);
bool isStalemated(Tile board[8][8]);
bool backtrack(int col, int row, Tile board[8][8]);
int pointCalculator(int col, int row, int j, int i, Tile board[8][8]);
bool ai(Tile board[8][8]);

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
	     << endl
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
	    default: cout << "Choose a valid option" << endl;
	}
    }
    while(input > 4 || input < 1);
}

void start()
{
    bool end = false;
    int turn = 1;
    Tile board[8][8];
    setupBoard(board);
    printBoard(board);
    
    do
    {
	if(turn % 2 == 1)
	{
	    askForMove(turn, board);
	    turn++;
	}
	else 
	{
	    ai(board);
	    turn++;
	}


	if(isStalemated(board))
	{
	    end = true;
	    cout << "Stalemate" << endl;
	}
	if(isKingInCheck('W', board))
	{
	    if(isCheckmated('W', board))
	    {
		end = true;
		cout << "Checkmate"
		    << endl
		    << "Black Wins"
		    << endl;
	    }
	}
	else if(isKingInCheck('B', board))
	{
	    if(isCheckmated('B', board))
	    {
		end = true;
		cout << "Checkmate"
		    << endl
		    << "White wins"
		    << endl;
	    }
	}

	printBoard(board);
    }
    while(!end);
}

void setupBoard(Tile board[8][8])
{
    int i, j;
    char c;
    //Making the center pieces value higher
    for(i = 0; i < 8; i++)
    {
	for(j = 0; j < 8; j++)
	{
	    board[i][j].setCoordinates(j, i);
	    if(i == 3 && j == 3 || i == 3 && j == 4 || i == 4 && j == 3 || 
		i == 4 && j ==4)
	    {
		board[i][j].setValue(2);
	    }
	    else
	    {
		board[i][j].setValue(1);
	    }
	}
    }
    //Place Pawns
    for(i = 1 , j = 0; j < 8; j++)
    {
	board[i][j].makePiece('P', 'B',board);
    }
    for(i = 6, j = 0; j < 8; j++)
    {
	board[i][j].makePiece('P', 'W',board);
    }
    //Place Queens
    board[0][4].makePiece('Q', 'B',board);
    board[7][4].makePiece('Q', 'W',board);
    //Place Kings
    board[0][3].makePiece('K', 'B',board);
    board[7][3].makePiece('K', 'W',board);
    //Place Bishops
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 2; j < 6;j+=3)
	{
	    board[i][j].makePiece('B', c,board);
	}
	c = 'W';
    }
    //Place Rooks
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 0; j < 8;j+=7)
	{
	    board[i][j].makePiece('R', c,board);
	}
	c = 'W';
    }
    //Place Knights
    c = 'B';
    for(i = 0; i < 8; i+=7)
    {
	for(j = 1; j < 7;j+=5)
	{
	    board[i][j].makePiece('H', c,board);
	}
	c = 'W';
    }
}

void printBoard(Tile board[8][8])
{
    cout << "  A  B  C  D  E  F  G  H" << endl;
    cout << "---------------------------" << endl;
    for(int i = 0; i < 8; i++)
    {
	cout << i+1;
	cout << '|';
	for(int j = 0; j < 8; j++)
	{

	    if(board[i][j].occupier != NULL)

		cout << board[i][j].occupier->getColor() << board[i][j].occupier->getSymbol();
	    else
		cout << "  ";
	    cout << '|';
	}
	cout << i+1;
	cout << endl;
	cout << "---------------------------";
	cout << endl;
    }
    cout << "  A  B  C  D  E  F  G  H" << endl;


}

bool movePiece(int ini_col, int ini_row ,int fin_col ,int fin_row, Tile board[8][8])
{
    char color;
    bool valid = false;
    Piece* eaten;
    bool ate = false;
    cout << "------------";
    cout << "Moving " << ini_col << ini_row << "to" << fin_col << fin_row ;
    cout << "------------" << endl;
    if(board[ini_row][ini_col].occupier->isMoveValid(fin_col, fin_row, board))
    {
	if(board[fin_row][fin_col].occupier != NULL)
	{
	    ate = true;
	    eaten = board[fin_row][fin_col].occupier;
	    board[fin_row][fin_col].removePiece();
	    cout << "Piece eaten" << endl;
	    
	}
	board[fin_row][fin_col].setPiece(board[ini_row][ini_col].occupier);
	board[ini_row][ini_col].removePiece();

	color = 'W';
	for(int i = 0; i < 2; i++)	
	{
	    if(isKingInCheck(color, board))
	    {
		cout << "King is in check" << endl;
		if(board[fin_row][fin_col].occupier->getColor() == color)
		{
		    //Undo move
		    undo(ini_col, ini_row, fin_col, fin_row, ate, eaten, board);
		}
	    }
	    color = 'B';
	}
	if(board[fin_row][fin_col].occupier != NULL
		&&board[fin_row][fin_col].occupier->getSymbol() == 'P')
	{
	    checkForPromotion(fin_col, fin_row, board);
	}
    }
    else 
    {
	cout << "Move invalid" << endl;
	return false;
    }
}

bool askForMove(int turn, Tile board[8][8])
{
    char mover;
    if(turn % 2 == 1) 
    {
	mover = 'W';
    }
    else
    {
	mover = 'B';
    }
    int ini_x, ini_y, fin_x, fin_y;
    string select, place;
    cout << "Pick a piece to move: ";
    getline(cin, select);
    ini_x = translate(select[0]);
    ini_y = translate(select[1]);
    
    if(board[ini_y][ini_x].occupier == NULL)
    {
	cout << "No piece in the space" << endl;
	return false;
    }
    if(board[ini_y][ini_x].occupier->getColor() != mover)
    {
	cout << "It's " << mover << "'s turn" << endl;
	return false;
    }
    cout << "Pick where to move the piece: ";
    getline(cin, place);
    fin_x = translate(place[0]);
    fin_y = translate(place[1]);
    if(ini_y >=8 || ini_x >= 8 || fin_x >= 8 || fin_y >= 8)
    {
	cout << "Please input valid coordinates" << endl;
	return false;
    }
    if(!movePiece(ini_x, ini_y, fin_x, fin_y, board))
	return false;
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

void checkForPromotion(int col, int row, Tile board[8][8])
{
    if(board[row][col].occupier->getColor() == 'W'
	    && row == 0)
    {
	board[row][col].occupier->promotion(col, row, board);
    }
    else if(board[row][col].occupier->getColor() == 'B'
	    && row == 7)
    {
	board[row][col].occupier->promotion(col, row, board);
    }
}
bool isKingInCheck(char color, Tile board[8][8])
{
    int x, y;
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    if(board[i][j].occupier != NULL 
		    && board[i][j].occupier->getSymbol() == 'K' 
		    && board[i][j].occupier->getColor() == color)
	    {
		x = board[i][j].occupier->getXPosition();
		y = board[i][j].occupier->getYPosition();
		i = 8; //to break the loop
		break;
	    }
	}
    }
    return board[y][x].occupier->isInCheck(board);

}

void undo(int ini_col, int ini_row, int fin_col, int fin_row, bool ate, Piece* eaten, Tile board[8][8])
{
    cout << "UNDOING MOVE" << endl;
    board[ini_row][ini_col].setPiece(board[fin_row][fin_col].occupier);
    board[fin_row][fin_col].removePiece();
    if(ate)
    {
	board[fin_row][fin_col].setPiece(eaten);
    }
    //If the piece is a pawn and already moved
    if(board[ini_row][ini_col].occupier->getSymbol() == 'P')
    {
	if(board[ini_row][ini_col].occupier->getColor() == 'W')
	{
	    if(board[ini_row][ini_col].occupier->getYPosition() != 6)
	    {
		board[ini_row][ini_col].occupier->setMoved();
	    }
	}
	else
	{
	    if(board[ini_row][ini_col].occupier->getYPosition() != 1)
	    {
		board[ini_row][ini_col].occupier->setMoved();
	    }
	}
    }
}

bool isCheckmated(char color, Tile board[8][8])
{
    Piece* eaten;
    bool ate = false;
    for(int i = 0; i < 8; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    ate = false;
	    eaten = NULL;
	    if(board[i][j].isOccupied()
		    && board[i][j].occupier->getColor() == color
		    ) 
	    {
		for(int y = 0; y < 8; y++)
		{
		    for(int x = 0; x < 8; x++)
		    {
			ate = false;
			eaten = NULL;
			if(board[i][j].occupier->isMoveValid(x, y, board))
			{
			    if(board[y][x].isOccupied())
			    {
				ate = true;
				eaten = board[y][x].occupier;
				board[y][x].removePiece();
			    }
			    board[y][x].setPiece(board[i][j].occupier);
			    board[i][j].removePiece();
			    
			    if(isKingInCheck(color, board))
			    {
				cout << "King is in check" << endl;
				//Undo move
				undo(j, i, x, y , ate, eaten, board);
			    }
			    else
			    {
				undo(j, i, x, y , ate, eaten, board);
				return false;
			    }
			}
		    }
		}
	    }
	}
    }
    return true;
}

bool isStalemated(Tile board[8][8])
{
    char color = 'W';
    for(int c = 0 ; c < 2; c++)
    {
	for(int i = 0; i < 8; i++)
	{
	    for(int j = 0; j < 8; j++)
	    {
		if(board[i][j].isOccupied())
		{
		    if(board[i][j].occupier->getColor() == color && board[i][j].occupier->hasMoves(board))
		    {
			return false;
		    }
		}
	    }
	}
    color = 'B';
    }
    return true;
}

int pointCalculator(int col, int row, int j, int i, Tile board[8][8])
{
    int points = 0;
    char color = board[row][col].occupier->getColor();
    char enemy_color;
    Piece* eaten = NULL;
    bool ate = false;
    enemy_color = color == 'W' ? 'B' : 'W';
    if(color == 'B')
    {
	if(board[row][col].occupier->isMoveValid(j, i, board))
	{
	    //If it can eat 
	    cout << "How";
	    if(board[i][j].isOccupied()
		    && board[i][j].occupier->getColor() != color)
	    {
		points += board[i][j].occupier->getValue();
	    }
	    points += board[i][j].getValue();
	
	    cout << "Far";
	    if(board[i][j].isOccupied())
	    {
		ate = true;
		eaten = board[i][j].occupier;
		board[i][j].removePiece();
	    }
	    board[i][j].setPiece(board[row][col].occupier);
	    board[row][col].removePiece();
	    
	    cout << "Ill";
	    if(isKingInCheck(color,board))
	    {
		undo(col, row, j, i,ate, eaten, board);
		return 0;
	    }
	    if(isKingInCheck(enemy_color,board))
	    {
		points += 10000000;
	    }
	    if(board[i][j].occupier->isInCheck(board))
	    {
		points -= board[i][j].occupier->getValue();
	    }

	    cout << "Go";
	    undo(col, row, j, i,ate, eaten, board);
	}
    }
    return points;
}

bool backtrack(int col, int row, Tile board[8][8])
{
   int points = 0;
   for(int i = 0; i < 8; i++)    
    {
	for(int j = 0; j < 8; j++)
	{ 	  
	    points = pointCalculator(col, row, j, i, board);
	    if(points >= 3)
	    {
		movePiece(col, row, j, i, board);
		return true;
	    }
	}
    }
   return false;
}

bool ai(Tile board[8][8])
{
    int x, y, i, j;
    bool end = false;
    for(i = 0; i < 8; i++)
    {
	for(j = 0; j < 8; j++)
	{
	    if(board[j][i].isOccupied())
	    {
		if(backtrack(i, j, board))
		{
		    return true;
		}
	    }
	}
    }
    for(;;)
    {
	i = rand() % 8;
	j = rand() % 8;
	x = rand() % 8;
	y = rand() % 8;
	if(board[j][i].isOccupied() && board[j][i].occupier->getColor() == 'B')
	{
	    if(board[j][i].occupier->isMoveValid(x,y,board))
	    {
		movePiece(i, j, x,y,board);
		return true;
	    }
	}
    }
    return true;
}
