using namespace std;

class Piece;

class Tile
{
    public:
	Tile();
	void setPiece(Piece* p);
	void removePiece();
    private:
	Piece* occupier;
};

