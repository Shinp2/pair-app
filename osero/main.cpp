#include "OseroGame.h"
#include "JsonIO.h"

int main(int argc,char** argv) {
	// jsonŒ`®‚Åó‚¯æ‚Á‚½ê‡
	JsonIO json;
	OseroGame game(json);
	game.singleRun();
	game.sendJsonForm();
	return 0;
}