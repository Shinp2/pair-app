#include "OseroGame.h"
#include "JsonIO.h"

int main(int argc, char** argv) {
	int flag = 0; // フラグ変数の初期化
	if (argc > 1) {
		if (std::string(argv[1]) == "--flip") {
			flag = 1; // フラグを立てる
		}
		else if (std::string(argv[1])=="--ai")
		{
			flag = 2; // AIモードのフラグを立てる
		}
		else if (std::string(argv[1]) == "--human") {
			flag = 3; // json形式で受け取るフラグを立てる
		}
		else if (std::string(argv[1]) == "--help") {
			// ヘルプメッセージを表示
			std::cout << "Usage: osero [--flip | --ai | --human | --help]" << std::endl;
			return 0;
		}
	}
	// json形式で受け取った場合

	JsonIO json;
	json.loadFromJsonForm();

	OseroGame game(json);

	if (flag == 1) {
		game.changePlayer(); // プレイヤーを変更
		game.sendJsonForm();
	}
	else if (flag == 2) {
		if (game.singleRun() != 0) {
			game.sendJsonForm();
		}
	}
	else if(flag == 3) {
		if (game.singleRun() != 0) {
			game.sendJsonForm();
		}
	}
	else {
		
	}
	return 0;
}
