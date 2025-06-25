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
	//JsonIO �Ŏ󂯎����lastMove���ꎞ�I�ɕێ�,Player class�ɓn�����߂Ɏg�p
	std::pair<int, int> lastMove;
protected:
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
	Player* currentPlayerPtr ;
	std::unique_ptr<Board> board;
	JsonIO jsonIO;

	void endGame();
public:
	void changePlayer();
	OseroGame(int size);
	OseroGame(JsonIO json);
	int checkGameOver();
	void start();
	void goGame();
	bool loadFromJsonForm();
	void sendJsonForm();
	bool singleRun();
	Board* getBoard() { return board.get(); }
};
