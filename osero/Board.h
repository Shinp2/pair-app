#pragma once
#include "common.h"

class Board
{
private:
	const int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	const int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

protected:
	std::vector<std::vector<int>> board;
	const int size;
public:
	Board(int _size = 8) : size(_size) {
		board.resize(_size, std::vector<int>(size, osero::NONE));
	}
	
	Board(int _size, Positions positions);

	int sizeOfBoard() const { return size; }
	bool isLegalMove(int row, int col, int playerType);
	// 石を置き、裏返し処理も行う
	void placeStone(int row, int col, int color);
	std::vector<std::pair<int, int>> getLegalMoves(int color);
	int countStones(int color);
	// 盤面をクリアする
	void clear();
	void flipDisks(int row, int col, int playerType);
	void flipDisks(int row, int col);
	int getCell(int row, int col);
	void setCell(int row, int col, int color);
};

