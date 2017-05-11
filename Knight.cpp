#include "Knight.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight()
{

}

bool Knight::isMoveValid(int col, int row, int board[8][8])
{
    return(checkMove(col, row, board));
}

bool Knight::checkMove(int col, int row, int board[8][8])
{
   int rise, run;
   rise = abs(y -row);
   run = abs(x - col);
   return(rise == 3 || rise == 1 && run == 3 || run == 1);
}


