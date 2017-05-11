#include "Bishop.h"

Bishop::Bishop()
{

}

bool Bishop::isMoveValid(int col, int row, int board[8][8])
{
    return (checkDiagonal(col, row, board));
}
