#pragma once
#include "common.h"
#include "Board.h"
class Player
{
protected:
	osero::PlayerColor playerColor;
public:
	Player(int color) : playerColor((osero::PlayerColor)color) {}
	virtual ~Player() = default;
	virtual std::pair<int, int> getMove( Board& board);
	osero::PlayerColor getColor();

};

