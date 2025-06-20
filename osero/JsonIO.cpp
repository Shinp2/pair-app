#include "JsonIO.h"

using json = nlohmann::json;

JsonIO::JsonIO()
{
	loadFromJsonForm();
}

bool JsonIO::loadFromJsonForm()
{
	Positions positions;
    std::string input((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());
    json j;
    try {
        j = json::parse(input);
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON from stdin: " << e.what() << std::endl;
        return false;
    }
    for (const auto& item : j) {
        int playerType = item["player"];
        int row = item["position"][0];
        int col = item["position"][1];
		positions.push_back({ playerType, {row, col} });
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
    
    return true;
}

int JsonIO::EmitJsonForm()
{
    
    return 0;
}

try {
    json j = json::parse(input);
    for (const auto& item : j) {
        int playerType = item["player"];
        int row = item["position"][0];
        int col = item["position"][1];
        positions.push_back({ playerType, {row, col} });
    }
}
catch (const json::parse_error& e) {
    std::cerr << "JSON parse error: " << e.what() << std::endl;
    return 1;
}
catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
}
game.placeDisks(positions); // Place initial disks

std::string input2;
std::getline(std::cin, input2);
int row = 0, col = 0;
try {
    json j2 = json::parse(input2);
    if (j2.size() != 2) {
        std::cerr << "Invalid input format. Expected a single dict object." << std::endl;
        return 1;
    }
    int playerType = j2["player"];
    row = j2["position"][0];
    col = j2["position"][1];
    game.changePlayer(playerType);
    game.makeMove(row, col); // Make the move

}
catch (const json::parse_error& e) {
    std::cerr << "JSON parse error: " << e.what() << std::endl;
    return 1;
}
catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
}