#include "Rook.h"
#include <iostream>

using namespace std;

Rook::Rook()
{
    value = 5;
    symbol = 'R';
    moved = false;
}

bool Rook::isMoveValid(int col, int row, Tile board[8][8])
{
    cout << "checking rook" << endl;
    if(checkHorizontal(col, row ,board) ||
    checkVertical(col, row, board))
    {
	if(!moved)
	{
	    moved = true;
	}
	return true;
    }
}
