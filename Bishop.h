#include "Queen.h"
using namespace std;

class Bishop: Queen
{
    public: 
	Bishop();
	bool isMoveValid(int col, int row, int board[8][8]);
};
