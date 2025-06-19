#pragma once
#include "common.h"
class Board
{
protected:
	std::vector<std::vector<int>> board;
	const int size;
public:
	bool isLegalMove(int x, int y, int color);
	// 石を置き、裏返し処理も行う
	void placeStone(int row, int col, int color);
	std::vector<std::pair<int, int>> getLegalMoves(int color);
	int countStones(int color);
	// 盤面をクリアする
	void clear();
	void flipDisks(int row, int col, int playerType);
	int getCell(int row, int col);
	void setCell(int row, int col, int color);
};

