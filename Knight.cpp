#include "Knight.h"
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
    return(checkMove(col, row, board));
}

bool Knight::checkMove(int col, int row, Tile board[8][8])
{
   float rise, run;
   rise = abs(this->y - row);
   cout << "Rise: " << rise << endl << y << "-" << row;
   run = abs(this->x - col);
   cout << "Run: " << run << endl;
   if(run == 0)
   {
       return false;
   }
   float slope = abs(rise/run);
   cout << "slope: " << slope << endl;
   return(slope == 0.5 || slope == 2 );
}


