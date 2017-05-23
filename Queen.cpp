#include "Queen.h"
#include <cmath>
#include <iostream>

using namespace std;

Queen::Queen()
{
    value = 9;
    symbol = 'Q';

}

bool Queen::checkDiagonal(int col, int row, Tile board[8][8])
{
    float rise, run;
    rise = y - row;
    run = x - col;
    if(run == 0 || rise == 0)
    {
	return false;
    }
    rise = abs(rise);
    run = abs(run);
    float slope = abs(rise/run);
    int delta;
    delta = rise > 1 ? rise - 1 : rise;
   
    //checking lower-left
    if(row > y && col < x)
    {
	for(int i = 0; i < delta; i++)	
	{
	    cout << "Checking " << col - i << " " << row - i << endl;
	    if(row - i >= 8 || row - i < 0 || col - i >= 8 || col - i < 0)
		continue;
	    if(board[row - i][col - i].isOccupied() && board[row - i][col - i].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    //checking lower-right
    else if(row > y && col > x )
    {
	for(int i = 0; i < delta; i++)	
	{
	    cout << "Checking " << col + i << " " << row - i << endl;
	    if(row - i >= 8 || row - i < 0 || col + i >= 8 || col + i < 0)
		continue;
	    if(board[row - i][col + i].isOccupied() && board[row - i][col + i].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    //checking upper-left
    else if(row < y && col < x)
    {
	for(int i = 0; i < delta; i++)	
	{
	    cout << "Checking " << col - i << " " << row + i << endl;
	    if(row + i >= 8 || row + i < 0 || col - i >= 8 || col - i < 0)
		continue;
	    if(board[row + i][col - i].isOccupied() && board[row + i][col - i].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    //checking upper-right
    else if(row < y && col > x)
    {
	for(int i = 0; i < delta; i++)	
	{
	    cout << "Checking " << col + i << " " << row + i << endl;
	    if(row + i >= 8 || row + i < 0 || col + i >= 8 || col + i < 0)
		continue;
	    if(board[row + i][col + i].isOccupied() && board[row + i][col + i].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    return(slope == 1.0);
}

bool Queen::checkVertical(int col, int row, Tile board[8][8])
{
    int delta;
    delta = abs(row-y);
    delta = delta > 1 ? delta - 1 : delta;
    if(row > y)
    {
	for(int i = 0; i < delta; i++ )
	{
	    cout << "Checking " << col << " " << row + i << endl;
	    if(row + i >= 8 || row + i < 0)
		continue;
	    if(board[row + i][col].isOccupied() && board[row + i][col].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    else if(y > row)
    {
	for(int i = 0; i < delta; i++ )
	{
	    cout << "Checking " << col << " " << row - i << endl;
	    if(row - i >= 8 || row - i < 0)
		continue;
	    if(board[row - i][col].isOccupied() && board[row - i][col].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }

    //TODO pls fix this shit idk why my mind isn't working ty
    return(x == col);
}

bool Queen::checkHorizontal(int col, int row, Tile board[8][8])
{
    int delta;
    delta = abs(col - x);
    delta = delta > 1 ? delta - 1 : delta;
    if(col > x)
    {
	for(int i = 0; i < delta; i++ )
	{
	    cout << "Checking " << col + i << " " << row << endl;
	    if(col + i >= 8 || col + i < 0)
		continue;
	    if(board[row][col + i].isOccupied() && board[row][col + i].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    else if(x > col)
    {
	for(int i = 0; i < delta; i++ )
	{
	    cout << "Checking " << col - i << " " << row << endl;
	    if(col - i >= 8 || col - i < 0)
		continue;
	    if(board[row][col - i].isOccupied() && board[row][col - i].occupier->getColor() == color)
	    {
		cout << "Space occupied" << endl;
		return false;
	    }
	}
    }
    return(y == row);
}

bool Queen::isMoveValid(int col,int row, Tile board[8][8])
{
    return (checkDiagonal(col, row, board) || checkHorizontal(col, row, board) || checkVertical(col, row, board));
}
