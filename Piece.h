#ifndef PIECE_H
#define PIECE_H

using namespace std;

class Tile;
class Piece
{
    public:
	virtual int getYPosition() = 0;
	virtual int getXPosition() = 0;
	void movePiece(int x, int y);
	void setXPosition(int coordinate);
	void setYPosition(int coordinate);
	void deletePiece();
	void setColor(char c);
	bool isMoveValid(int x, int y, Tile board[8][8]);
	char getColor();
    protected:
	int x, y, value;
	char color;
};

#endif
