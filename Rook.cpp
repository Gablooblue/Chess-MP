#include "Rook.h"
#include <iostream>

using namespace std;

Rook::Rook()
{
    value = 5;
    symbol = 'R';
}

bool Rook::isMoveValid(int col, int row, Tile board[8][8])
{
    return (checkHorizontal(col, row ,board) ||
    checkVertical(col, row, board));
}
