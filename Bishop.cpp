#include "Bishop.h"

Bishop::Bishop()
{

}

bool Bishop::isMoveValid(int col, int row, int board[8][8])
{
    checkDiagonal(col, row, board);
}
