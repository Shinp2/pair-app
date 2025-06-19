#include "Player.h"
class Human :
    public Player
{
public:
    std::pair<int, int> getMove(const Board& board) override;
};
