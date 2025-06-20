
#include "Player.h"
class Ai :
    public Player
{
protected:
    // ミニマックス法の深さ制限
    const int MAX_DEPTH = 5; // 深さを5に設定
    // 評価関数の重み
    const int CORNER_WEIGHT = 1000;
    const int EDGE_WEIGHT = 500;
    const int CENTER_WEIGHT = 300;
    // 盤面の評価関数
    int evaluateCorner(const Board& board, int playerType);
    int evaluateEdge(const Board& board, int playerType);
	int evaluateCenter(const Board& board, int playerType);
public:
    Ai(int color) : Player(color) {}; // コンストラクタを追加
    bool getMove(Board& board) override; // 修正: 基底クラスの関数シグネチャに一致させる
    int minimax(int depth, bool maximizingPlayer, int turnPlayer, int evalPlayerType);
    // 盤面を評価
    int evaluateBoard(int playerType);
}; 
