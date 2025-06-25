#include "Board.h"
#include <print> // C++23のprint用

// positionsを使用して、初期配置を設定する
Board::Board(int _size, Positions positions) : size(_size) {
    board.resize(_size, std::vector<int>(size, osero::NONE));
    for (const auto& [playerType, pos] : positions) { // 分解代入
        auto [row, col] = pos;
        board[row][col] = playerType;
    }
}

bool Board::isLegalMove(int row, int col, int playerType)
{
    int opponent = (playerType == osero::BLACK) ? osero::WHITE : osero::BLACK;
    for (int dir = 0; dir < 8; ++dir) {
        int nx = row + dx[dir];
        int ny = col + dy[dir];
        bool foundOpponent = false;

        while (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size()) {
            if (board[nx][ny] == opponent) {
                foundOpponent = true;
                nx += dx[dir];
                ny += dy[dir];
            }
            else if (board[nx][ny] == playerType && foundOpponent) {
                return true;
            }
            else {
                break;
            }
        }
    }
    return false;
}

void Board::placeStone(int row, int col, int playerType)
{
    if (board[row][col] == 0 && isLegalMove(row, col, playerType)) {
        board[row][col] = playerType;
        flipDisks(row, col, playerType);
    }
    else {
        std::print("error in osero.cpp class board in void placeStone(int row,int col,int playerType)!\n");
    }
}

std::vector<std::pair<int, int>> Board::getLegalMoves(int playerType)
{
    return {};
}

int Board::countStones(int playerType)
{
    int count = 0;
    for (const auto& row : board) {
        for (auto cell : row) {
            if (cell == playerType) {
                ++count;
            }
        }
    }
    return count;
}

void Board::clear()
{
    for (auto& row : board) {
        for (auto& cell : row) {
            cell = osero::NONE;
        }
    }
}

void Board::flipDisks(int row, int col, int playerType)
{
    lastFlippedPositions.clear();
    int opponent = (playerType == osero::BLACK) ? osero::WHITE : osero::BLACK;

    for (int dir = 0; dir < 8; ++dir) {
        int nx = row + dx[dir];
        int ny = col + dy[dir];
        std::vector<std::pair<int, int>> toFlip;

        while (nx >= 0 && nx < board[0].size() && ny >= 0 && ny < board.size() && board[nx][ny] == opponent) {
            toFlip.push_back({ nx, ny });
            nx += dx[dir];
            ny += dy[dir];
        }

        if (nx >= 0 && nx < board[0].size() && ny >= 0 && ny < board.size() && board[nx][ny] == playerType) {
            for (auto p : toFlip) {
                board[p.first][p.second] = playerType;
                lastFlippedPositions.push_back(p);
            }
        }
    }
}

void Board::flipDisks(int row, int col)
{
    if (board[row][col] == osero::NONE) {
        return;
    }
    else {
        board[row][col] = (board[row][col] == osero::BLACK) ? osero::WHITE : osero::BLACK;
        lastFlippedPositions.push_back({ row, col });
    }
}

int Board::getCell(int row, int col)
{
    return board[row][col];
}

void Board::setCell(int row, int col, int color)
{
    board[row][col] = color;
}
