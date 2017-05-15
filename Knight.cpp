#include "Knight.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight()
{
    this->value = 3;
}

bool Knight::isMoveValid(int col, int row, Tile  board[8][8])
{
    return(checkMove(col, row, board));
}

bool Knight::checkMove(int col, int row, Tile  board[8][8])
{
   int rise, run;
   rise = abs(this->y -row);
   run = abs(this->x - col);
   return(rise == 3 || rise == 1 && run == 3 || run == 1);
}


