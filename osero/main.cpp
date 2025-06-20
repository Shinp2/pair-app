#include "OseroGame.h"
#include "JsonIO.h"

int main(int argc,char** argv) {
	int flag = 0; // フラグ変数の初期化
	if (argc > 1) {
		if (argv[1] == "--flip") {
			flag = 1; // フラグを立てる
		}else if(argv[1] == "--json") {
			flag = 2; // json形式で受け取るフラグを立てる
		} else if (argv[1] == "--help") {
			// ヘルプメッセージを表示
			std::cout << "Usage: osero [options]\n"
					  << "Options:\n"
					  << "  --flip   : Flip the board with json form\n"
					  << "  --json   : Run with json form\n"
					  << "  --help   : Show this help message\n";
			return 0;
	}
	// json形式で受け取った場合
	JsonIO json;
	OseroGame game(json);
	if (flag == 1) {
		game.sendJsonForm();
	}else if (flag == 2) {
		game.singleRun();
		game.sendJsonForm();
	}

	return 0;
}