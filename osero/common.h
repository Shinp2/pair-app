#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <string>
namespace osero {
	enum class GameState { RUNNING, PLAYER1_WIN, PLAYER2_WIN, DRAW };
	enum PlayerColor { NONE, BLACK, WHITE };
}