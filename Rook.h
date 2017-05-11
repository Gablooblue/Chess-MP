#include "Queen.h"
using namespace std;

class Rook: Queen
{
    public:
	Rook();
	bool isMoveValid(int col, int row, int board[8][8]);
};
