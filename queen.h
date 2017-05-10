using namespace std;

class Queen: public Piece
{
    public: 
	Queen();
	int getYPosition();
	int getXPosition();
	bool checkDiagonal(int x, int y, int board[8][8]);
	bool checkHorizontal(int y, int board[8][8]);
	bool checkVertical(int x, int board[8][8]);
	bool isMoveValid(int x, int y, int board[8][8]);
};
