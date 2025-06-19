
#include "Human.h"

std::pair<int, int> Human::getMove(Board& board)
{
	int row, col;

	board.placeStone(row, col, this->playerColor);
	return std::pair<int, int>();
}
