
#include "Player.h"
class Ai :
    public Player
{
public:
    std::pair<int, int> getMove(const Board& board) override;
    int minimax(int depth, bool maximizingPlayer, int turnPlayer, int evalPlayerType);
    // ”Õ–Ê‚ð•]‰¿
    int evaluateBoard(int playerType);
};
