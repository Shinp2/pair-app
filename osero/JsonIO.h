#pragma once
#include "common.h"
#include "Board.h"
#include "json.hpp"

using json = nlohmann::json;

class JsonIO
{
protected:
	int size = BOARD_SIZE_INI;
public:
	JsonIO();
	std::unique_ptr<Board> board;
	bool loadFromJsonForm();
	int EmitJsonForm();
};

