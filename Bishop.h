#include "Queen.h"
using namespace std;

class Bishop: public Queen
{
    public: 
	Bishop();
	bool isMoveValid(int col, int row, int board[8][8]);
};
