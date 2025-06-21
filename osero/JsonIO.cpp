#include "JsonIO.h"

JsonIO::JsonIO()
{
}
JsonIO::JsonIO(const JsonIO& other)
    : size(other.size),
    lastMove(other.lastMove),
    hasLastMove(other.hasLastMove),
    board(other.board ? std::make_unique<Board>(*other.board) : nullptr) // `board` のコピーを作成
{
}

bool JsonIO::loadFromJsonForm()
{
	Positions positions;
    std::string input(
        (std::istreambuf_iterator<char>(std::cin)),
        std::istreambuf_iterator<char>()
    );
    json j = json::object();;

    try {
        j = json::parse(input);
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON from stdin: " << e.what() << std::endl;
        return false;
    }
    

    // "board"配列からplayerとpositionを取得
    if (j.contains("board")) {
        for (const auto& item : j["board"]) {
            int playerType = item["player"];
            int row = item["position"][0];
            int col = item["position"][1];
            positions.push_back({ playerType, {row, col} });
        }
    }

    if (j.contains("move")) {
		lastMove = j["move"];		
        hasLastMove = true;
    }
    // ボードサイズや初期配置を JSON から取得
    if (j.contains("boardSize")) {
        this->size = j["boardSize"];	
    }
    else {
		size = 8; // デフォルトのボードサイズ
    }

    board = std::make_unique<Board>(size, positions); // 初期配置を設定
    
    if (j.contains("flip")) {
        for(const auto& item : j["flip"]) {
            int row = item[0];
            int col = item[1];
            board->flipDisks(row, col);
		}
		
    }

    return true;
}

int JsonIO::EmitJsonForm(Board& board,int endFlag)
{
    json j = json::array();
	osero::PlayerColor color = osero::NONE;
    for (int row = 0; row < board.sizeOfBoard(); ++row) {
        for (int col = 0; col < board.sizeOfBoard(); ++col) {
			color = (osero::PlayerColor)board.getCell(row, col);
            if (color != osero::NONE) {
                j.push_back({ {"player", (int)color}, {"position", {row, col}} });
            }
        }
    }
    // lastFlippedPositionsをJSON配列に変換
    json flips = json::array();
    for (const auto& pos : board.getLastFlippedPositions()) {
        flips.push_back({ pos.first, pos.second });
    }
	json outputFormat = json::object();
	outputFormat["board"] = j;
    outputFormat["flips"] = flips;
	outputFormat["endFlag"] = endFlag;
    std::cout << outputFormat;
    return 0;
}

