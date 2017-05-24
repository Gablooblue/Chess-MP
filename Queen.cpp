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
    int rise, run, delta;
    rise = y - row;
    run = x - col;
    if(run == 0 || rise == 0)
    {
	return false;
    }
    rise = abs(rise);
    run = abs(run);
    delta = rise > 1 ? rise  : rise + 1;
     
    if(rise == run)
    {
	//checking upper-left
	if(row < y && col < x)
	{
	    for(int i = 1; i < delta; i++)	
	    {
		if(y - i >= 8 || y - i < 0 || x - i >= 8 || x - i < 0)
		    continue;
		if(board[y - i][x - i].isOccupied()) 
		{
		    if(board[y - i][x - i].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( y - i != row || x - i != col )
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
	//checking upper-right
	else if(row < y && col > x )
	{
	    for(int i = 1; i < delta; i++)	
	    {
		if(y - i >= 8 || y - i < 0 || x + i >= 8 || x + i < 0)
		    continue;
		if(board[y - i][x + i].isOccupied()) 
		{
		    if(board[y - i][x + i].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( y - i != row || x + i != col )
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
	//checking lower-left
	else if(row > y && x > col)
	{
	    for(int i = 1; i < delta; i++)	
	    {
		if(y + i >= 8 || y + i < 0 || x - i >= 8 || x - i < 0)
		    continue;
		if(board[y + i][x - i].isOccupied()) 
		{
		    if(board[y + i][x - i].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( y + i != row || x - i != col )
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
	//checking lower-right
	else if(row > y && col > x)
	{
	    for(int i = 1; i < delta; i++)	
	    {
		if(y + i >= 8 || y + i < 0 || x + i >= 8 || x + i < 0)
		    continue;
		if(board[y + i][x + i].isOccupied()) 
		{
		    if(board[y + i][x + i].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( y + i != row || x + i != col )
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
    }
    else
	return false;
}

bool Queen::checkVertical(int col, int row, Tile board[8][8])
{
    int delta;
    if (row - y == 0)
    {
	return false;
    }
    delta = abs(row-y);
    delta = delta > 1 ? delta : delta + 1;
    if(x == col)
    {
	if(row > y)
	{
	    for(int i = 1; i < delta; i++ )
	    {
		if( y + i >= 8 || y + i < 0)
		    continue;
		if(board[y + i][x].isOccupied()) 
		{
		    if(board[y + i][x].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( y + i != row )
			{
			    
			    return false;
			}
		    }
		}
		
	    }
	}
	else if(row < y )
	{
	    for(int i = 1; i < delta; i++ )
	    {
		if( y- i >= 8 || y - i < 0)
		    continue;
		if(board[y - i][x].isOccupied()) 
		{
		    if(board[y - i][x].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( y - i != row )
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
    }
    else
	return false;
}

bool Queen::checkHorizontal(int col, int row, Tile board[8][8])
{
    int delta;
    if(col - x == 0)
	return false;

    delta = abs(col - x);
    delta = delta > 1 ? delta  : delta + 1;
    if(y == row)
    {
	if(col > x)
	{
	    for(int i = 1; i < delta; i++ )
	    {
		if( x+ i >= 8 || x + i < 0)
		    continue;
		if(board[y][x + i].isOccupied()) 
		{
		    if(board[y][x + i].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( x + i != col)
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
	else if(x > col)
	{
	    for(int i = 1; i < delta; i++ )
	    {
		if(x - i >= 8 || x - i < 0)
		    continue;
		if(board[y][x - i].isOccupied()) 
		{
		    if(board[y][x - i].occupier->getColor() == color)
		    {
			
			return false;
		    }
		    else
		    {
			if( x - i != col)
			{
			    
			    return false;
			}
		    }
		}
	    }
	}
    }
    else
	return false;
}

bool Queen::isMoveValid(int col,int row, Tile board[8][8])
{
    return (checkDiagonal(col, row, board) || checkHorizontal(col, row, board) || checkVertical(col, row, board));
}
