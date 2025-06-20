#include "Player.h"
#include "json.hpp" 

class Human :
    public Player
{
public:
    bool getMove(Board& board) override;
    void setLastMove(const std::pair<int, int>& move); 
private:
    std::pair<int, int> lastMove;
};
