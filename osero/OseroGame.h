#pragma once
#include "common.h"
#include "Player.h"
#include "Board.h"
class OseroGame
{

protected:
	Player* player1;
	Player* player2;
	Board board;
public:
	void start();
protected:
	void changePlayer();
	void endGame();
public:
	int checkGameOver()const;
};
