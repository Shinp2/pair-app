
#include "Board.h"

//positionsを使用して、初期配置を設定する
Board::Board(int _size, Positions positions):size(_size) {  
    board.resize(_size, std::vector<int>(size, osero::NONE));  
    for (const auto& pos : positions) {  
        int playerType = std::get<0>(pos);  
        int row = std::get<1>(pos).first;  
        int col = std::get<1>(pos).second;  
        board[row][col] = playerType;  
    }  
}

bool Board::isLegalMove(int row, int col, int playerType)
{
    // playerType: BLACK or WHITE
    std::vector<std::pair<int, int>> legalMoves;
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
    // 指定位置に石を置けるか判定
    return false;
}


// 石を置き、裏返し処理も行う
void Board::placeStone(int row, int col, int playerType)
{
	// playerType: BLACK or WHITE
    if (board[row][col] == 0 && isLegalMove(row, col, playerType)) {
        board[row][col] = playerType; // Place the disk
        flipDisks(row, col, playerType);
    }
    else {
        std::cout << "error in osero.cpp class board in void placeStone(int row,int col,int playerType)!" << std::endl;
    }
}

// 配置可能な場所を見つける
std::vector<std::pair<int, int>> Board::getLegalMoves(int playerType)
{

    return std::vector<std::pair<int, int>>();
}

// 石の数を数える
int Board::countStones(int playerType)
{
	int count = 0;
    for(int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == playerType) {
                ++count;
            }
        }
	}
    return count;
}

// 盤面をクリアする
void Board::clear()
{
    for(int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            board[i][j] = osero::NONE;
        }
	}
}
// 石を置く処理と裏返し処理を行う
void Board::flipDisks(int row, int col, int playerType)
{
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
            }
        }
    }
}

void Board::flipDisks(int row, int col)
{
	board[row][col] = (board[row][col] == osero::BLACK) ? osero::WHITE : osero::BLACK;
}

int Board::getCell(int row, int col)
{
    return board[row][col];
}

void Board::setCell(int row, int col, int color)
{
	board[row][col] = color;
}
