#pragma once
#include "common.h"
#include "Ai.h"
#include "Human.h"
#include "Board.h"
#include <memory>

class OseroGame
{
private:
	osero::GameState gameState = osero::GameState::RUNNING;
protected:
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
	Player* currentPlayerPtr;
	Board board;
	void changePlayer();
	void endGame();
public:
	OseroGame::OseroGame(int size);
	OseroGame::OseroGame(int size,int side);
	int checkGameOver();
	void start();

	void goGame();
};
