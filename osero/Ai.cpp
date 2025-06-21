
#include "Ai.h"


bool Ai::getMove(Board& board)
{
    osero::PlayerColor oppositColor =(this->playerColor == osero::BLACK ? osero::WHITE : osero::BLACK);

    int bestScore = -10000;
    int bestRow = -1, bestCol = -1;
    for (int row = 0; row < board.sizeOfBoard(); ++row) {
        for (int col = 0; col < board.sizeOfBoard(); ++col) {
            if (board.getCell(row,col) == osero::NONE && board.isLegalMove(row, col, this->playerColor)) {
                auto newBoard = board;

                newBoard.placeStone(row, col, playerColor);

                int score = minimax(newBoard, MAX_DEPTH - 1, true, oppositColor, this->playerColor);
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = row;
                    bestCol = col;
                }
            }
        }
    }
    if (bestRow != -1 && bestCol != -1) {
        board.placeStone(bestRow, bestCol,playerColor);
    }
    else {
        //Å@éËÇ™å©Ç¬Ç©ÇÁÇ»Ç©Ç¡ÇΩ
    }
    
}

int Ai::minimax(Board& board, int depth, bool maximizingPlayer, int turnPlayer, int evalPlayerType)
{
    osero::PlayerColor opponent = (turnPlayer == osero::BLACK ? osero::WHITE:osero::BLACK);
    if (depth <= 0) {
        return evaluateBoard(board);
    }
    int bestScore = maximizingPlayer ? -10000 : 10000;
    bool hasMove = false;
    for (int row = 0; row < board.sizeOfBoard(); ++row) {
        for (int col = 0; col < board.sizeOfBoard(); ++col) {
            if (board.getCell(row,col) == osero::NONE && board.isLegalMove(row, col, playerColor)) {
                hasMove = true;
                auto newBoard = board;
                newBoard.placeStone(row, col, playerColor);

                int score = minimax(newBoard, depth - 1, !maximizingPlayer,opponent, evalPlayerType);
                if (maximizingPlayer) {
                    bestScore = std::max(bestScore, score);
                }
                else {
                    bestScore = std::min(bestScore, score);
                }
            }
        }
    }
    if (!hasMove) {
        return evaluateBoard(board);
    }
    return bestScore;
}

// î’ñ Çï]âø
int Ai::evaluateBoard(Board& board)
{
    osero::PlayerColor opponent = (this->playerColor == osero::BLACK) ? osero::WHITE : osero::BLACK;
    int score = 0;

    // 1. êŒÇÃêî
    int myStones = 0, oppStones = 0;
    for (int row = 0; row < board.sizeOfBoard(); ++row) {
        for (int col = 0; col < board.sizeOfBoard(); ++col) {
            int cell = board.getCell(row, col);
            if (cell == playerColor) myStones++;
            else if (cell == opponent) oppStones++;
        }
    }
    score += myStones - oppStones;

    // 2. äpÇÃï]âø
    score += CORNER_WEIGHT * evaluateCorner(board, playerColor);
    score -= CORNER_WEIGHT * evaluateCorner(board, opponent);

    // 3. ï”ÇÃï]âø
    score += EDGE_WEIGHT * evaluateEdge(board, playerColor);
    score -= EDGE_WEIGHT * evaluateEdge(board, opponent);

    // 4. íÜâõÇÃï]âø
    score += CENTER_WEIGHT * evaluateCenter(board, playerColor);
    score -= CENTER_WEIGHT * evaluateCenter(board, opponent);

    return score;
}

int evaluateBoard(const std::vector<std::vector<int>>& board, int playerType) {

}

int minimax(std::vector<std::vector<int>> board, int depth, bool maximizingPlayer, int turnPlayer, int evalPlayerType) {

}

int evaluateCorner(Board& board, int playerType) {
    // äpÇÃï]âøÉçÉWÉbÉN
}


