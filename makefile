all: chess.cpp
	g++ -o chess.exe Piece.cpp Queen.cpp Tile.cpp Bishop.cpp King.cpp Knight.cpp Pawn.cpp Rook.cpp chess.cpp   
