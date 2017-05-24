#include "Bishop.h"
#include <iostream>

using namespace std;

Bishop::Bishop()
{
    value = 3;
    symbol = 'B';
}

bool Bishop::isMoveValid(int col, int row, Tile board[8][8])
{
    return (checkDiagonal(col, row, board));
}
