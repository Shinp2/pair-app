#include "Player.h"
#include "json.hpp" 

class Human :
    public Player
{
public:
    std::pair<int, int> getMove( Board& board) override;
};
