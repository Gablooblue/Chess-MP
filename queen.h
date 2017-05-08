using namespace std;

class Queen: public Piece
{
    public: 
	int getYPosition();
	int getXPosition();
	bool checkDiagonal(int x, int y, int board[8][8]);
	bool checkHorizontal(int x, int y, int board[8][8]);
	bool checkVertical(int x, int y, int board[8][8]);
    private:
	int x,y;
}
