#pragma once

#include <vector>
#include <tuple>
#include <utility>
#include <iostream>
#include <string>

#define BOARD_SIZE_INI 8

using Positions = std::vector<std::tuple<int, std::pair<int, int>>>;

namespace osero {
	enum class GameState { RUNNING, PLAYER1_WIN, PLAYER2_WIN, DRAW };
	enum PlayerColor { NONE, BLACK, WHITE };
}