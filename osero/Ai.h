
#include "Player.h"
class Ai :
    public Player
{
public:
    std::pair<int, int> getMove(const Board& board) override;
};
