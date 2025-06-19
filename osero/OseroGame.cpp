
#include "OseroGame.h"

OseroGame::OseroGame(int size)  
	: player1(std::make_unique<Human>(osero::BLACK)),
      player2(std::make_unique<Player>(osero::WHITE)), 
      board(size)  
{  
	// コンストラクタの初期化リストでメンバ変数を初期化
}
void OseroGame::start()
{
	// TODO: ここに実装コードを追加します.
}

void OseroGame::changePlayer()
{
    currentPlayerPtr = (currentPlayerPtr == player1.get()) ? player2.get() : player1.get();
}

void OseroGame::endGame()
{
	// TODO: ここに実装コードを追加します.
}

int OseroGame::checkGameOver()  
{  
    
    const int size = board.sizeOfBoard(); 
	int currentPlayer = this->currentPlayerPtr->getColor(); // 現在のプレイヤーの色を取得
	int oppositePlayer = (currentPlayer == osero::BLACK) ? osero::WHITE : osero::BLACK;
	unsigned char continueFlag = 0; // 続行フラグを初期化

    for (int row = 0; row < size; ++row) {  
        for (int col = 0; col < size; ++col) {  
            if (board.getCell(row,col) == osero::NONE && board.isLegalMove(row, col, currentPlayer)) {
                return 1; //設置できるため続行 
            }  
            else if (board.getCell(row, col) == osero::NONE && board.isLegalMove(row, col, oppositePlayer)) {
				continueFlag = 1; // 相手の手番で設置可能な場所があるため続行フラグを立てる
                continue;
            }
        }  
    }  
    if(continueFlag == 0) { // どちらも設置できない場合
        endGame(); //終了処理を呼び出す
        return 0; // 終了
    }
    else {
        changePlayer(); // プレイヤーを交代
		return 1; // 続行
    }

}

void OseroGame::goGame()
{
    try {
        //盤面出力処理をここに記述
        int row, col;
        currentPlayerPtr = this->player1.get(); // 初期プレイヤーを設定
        while (this->checkGameOver()) {
            
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input. Please enter two integers for row and column.");
            }
            currentPlayerPtr->getMove(row, col);
			// 盤面の状態を表示する処理をここに記述
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
