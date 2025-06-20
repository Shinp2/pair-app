#pragma once
#include "common.h"
#include "Board.h"
#include "json.hpp"

using json = nlohmann::json;

class JsonIO
{
protected:
	int size = BOARD_SIZE_INI;
	std::pair<int, int> lastMove;
	bool hasLastMove = false;
public:
	JsonIO();
	std::unique_ptr<Board> board;
	bool loadFromJsonForm();
	int EmitJsonForm();
	bool hasLastMoveSet() const { return hasLastMove; }
	std::pair<int, int> getLastMove() const { return lastMove; }
};

