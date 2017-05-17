#ifndef PIECE_H
#define PIECE_H

using namespace std;

class Tile;
class Piece
{
    public:
	int getYPosition();
	int getXPosition();
	void movePiece(int x, int y);
	void setXPosition(int coordinate);
	void setYPosition(int coordinate);
	void deletePiece();
	void setColor(char c);
	virtual bool isMoveValid(int x, int y, Tile board[8][8]);
	char getSymbol();
	char getColor();
    protected:
	int x, y, value;
	char color, symbol;
};

#endif
