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
	virtual bool getMove(Board& board) = 0;
	osero::PlayerColor getColor();
}; // © ‚±‚±‚ÉƒZƒ~ƒRƒƒ“‚ğ’Ç‰Á
