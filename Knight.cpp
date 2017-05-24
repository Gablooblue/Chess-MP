#include "Knight.h"
#include "Tile.h"
#include <iostream>
#include <cmath>

using namespace std;

Knight::Knight()
{
    value = 3;
    symbol = 'H';

}

bool Knight::isMoveValid(int col, int row, Tile board[8][8])
{
    cout << "Checking Knight" << x << y << endl;
    return(checkMove(col, row, board));
}

bool Knight::checkMove(int col, int row, Tile board[8][8])
{
   float rise, run;
   rise = abs(this->y - row);
   run = abs(this->x - col);
   if(rise > 2 || run > 2 || run == 0 || rise == 0)
   {
       return false;
   }
   if(board[row][col].isOccupied() && board[row][col].occupier->getColor() == this->color)
    {
       return false;
    }
   float slope = abs(rise/run);
   return(slope == 0.5 || slope == 2);
}


