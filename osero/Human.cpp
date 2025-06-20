
#include "Human.h"

bool Human::getMove(Board& board)
{
	int row = lastMove.first, col = lastMove.second;
	if (board.isLegalMove(row, col, this->playerColor)) {
		board.placeStone(row, col, this->playerColor);
		return true;
	}
	else {
		return false;
	}
}
void Human::setLastMove(const std::pair<int, int>& move) {
	lastMove = move;
}