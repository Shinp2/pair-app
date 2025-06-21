#pragma once
#include "common.h"
#include "Ai.h"
#include "Human.h"
#include "Board.h"
#include "JsonIO.h"
#include <memory>

class OseroGame
{
private:
	//JsonIO ‚Åó‚¯æ‚Á‚½lastMove‚ğˆê“I‚É•Û,Player class‚É“n‚·‚½‚ß‚Ég—p
	std::pair<int, int> lastMove;
protected:
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
	Player* currentPlayerPtr ;
	std::unique_ptr<Board> board;
	JsonIO jsonIO;
	void changePlayer();
	void endGame();
public:
	OseroGame(int size);
	OseroGame(JsonIO json);
	int checkGameOver();
	void start();
	void goGame();
	bool loadFromJsonForm();
	void sendJsonForm();
	void singleRun();
	Board* getBoard() { return board.get(); }
};
