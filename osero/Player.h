#pragma once
#include "common.h"
#include "Board.h"
class Player
{
public:
	Player(int color) : color(color) {}
	virtual ~Player() = default;
	virtual std::pair<int, int> getMove(const Board& board);
	int getColor();
protected:
	int color;
};

