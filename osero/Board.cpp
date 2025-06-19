
#include "Board.h"


bool Board::isLegalMove(int x, int y, int color)
{
    // 指定位置に石を置けるか判定
    return false;
}


// 石を置き、裏返し処理も行う
void Board::placeStone(int row, int col, int color)
{
    // TODO: ここに実装コードを追加します.
}

// 配置可能な場所を見つける
std::vector<std::pair<int, int>> Board::getLegalMoves(int color)
{
    // TODO: ここに実装コードを追加します.
    return std::vector<std::pair<int, int>>();
}

// 医師の数を数える
int Board::countStones(int color)
{
    // TODO: ここに実装コードを追加します.
    return 0;
}

// 盤面をクリアする
void Board::clear()
{
    // TODO: ここに実装コードを追加します.
}

void Board::flipDisks(int row, int col, int playerType)
{
    // TODO: ここに実装コードを追加します.
}

int Board::getCell(int row, int col)
{
    // TODO: ここに実装コードを追加します.
    return 0;
}

void Board::setCell(int row, int col, int color)
{
    // TODO: ここに実装コードを追加します.
}
