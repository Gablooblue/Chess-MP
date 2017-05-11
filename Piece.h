using namespace std;

class Piece
{
    public:
	virtual int getYPosition() = 0;
	virtual int getXPosition() = 0;
	void movePiece(int x, int y);
	void setXPosition(int coordinate);
	void setYPosition(int coordinate);
	bool isMoveValid(int x, int y, int board[8][8]);
    protected:
	int x, y;
	char color;
};
