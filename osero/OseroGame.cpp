
#include "OseroGame.h"

OseroGame::OseroGame(int size)  
	: player1(std::make_unique<Human>(osero::BLACK)),
      player2(std::make_unique<Human>(osero::WHITE)), 
      board(std::make_unique<Board>(size))
{  
	// コンストラクタの初期化リストでメンバ変数を初期化
}

// JSONからの初期化を行うコンストラクタ
// Webブラウザ1手毎に呼び出すことを想定しplayer1はHumanとして初期化し、player2はAiとして初期化
// GameOsero内では１手分のみ処理を行う
OseroGame::OseroGame(JsonIO json)
    : player1(std::make_unique<Human>(osero::BLACK)),
    player2(std::make_unique<Ai>(osero::WHITE)),
    board(std::move(json.board))
{  

    if (json.hasLastMoveSet()) {
        static_cast<Human*>(player1.get())->setLastMove(json.getLastMove());
    }
	// unique_ptrを使用してBoardオブジェクトを受け取るコンストラクタ
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
    
    const int size = board->sizeOfBoard(); 
	int currentPlayer = this->currentPlayerPtr->getColor(); // 現在のプレイヤーの色を取得
	int oppositePlayer = (currentPlayer == osero::BLACK) ? osero::WHITE : osero::BLACK;
	unsigned char continueFlag = 0; // 続行フラグを初期化

    for (int row = 0; row < size; ++row) {  
        for (int col = 0; col < size; ++col) {  
            if (board->getCell(row,col) == osero::NONE && board->isLegalMove(row, col, currentPlayer)) {
                return 1; //設置できるため続行 
            }  
            else if (board->getCell(row, col) == osero::NONE && board->isLegalMove(row, col, oppositePlayer)) {
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
        currentPlayerPtr = this->player1.get(); // 初期プレイヤーを設定
        while (this->checkGameOver()) {
            
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input. Please enter two integers for row and column.");
            }
            currentPlayerPtr->getMove(*board);
			// 盤面の状態を表示する処理をここに記述
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
