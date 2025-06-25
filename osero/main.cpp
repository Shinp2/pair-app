#include "OseroGame.h"
#include "JsonIO.h"

int main(int argc, char** argv) {
	int flag = 0; // �t���O�ϐ��̏�����
	if (argc > 1) {
		if (std::string(argv[1]) == "--flip") {
			flag = 1; // �t���O�𗧂Ă�
		}
		else if (std::string(argv[1])=="--ai")
		{
			flag = 2; // AI���[�h�̃t���O�𗧂Ă�
		}
		else if (std::string(argv[1]) == "--human") {
			flag = 3; // json�`���Ŏ󂯎��t���O�𗧂Ă�
		}
		else if (std::string(argv[1]) == "--help") {
			// �w���v���b�Z�[�W��\��
			std::cout << "Usage: osero [--flip | --ai | --human | --help]" << std::endl;
			return 0;
		}
	}
	// json�`���Ŏ󂯎�����ꍇ

	JsonIO json;
	json.loadFromJsonForm();

	OseroGame game(json);

	if (flag == 1) {
		game.changePlayer(); // �v���C���[��ύX
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
