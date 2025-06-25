
#include "OseroGame.h"

OseroGame::OseroGame(int size)  
	: player1(std::make_unique<Human>(osero::BLACK)),
      player2(std::make_unique<Human>(osero::WHITE)), 
      board(std::make_unique<Board>(size))
{  
	// �R���X�g���N�^�̏��������X�g�Ń����o�ϐ���������
}

// JSON����̏��������s���R���X�g���N�^
// Web�u���E�U1�薈�ɌĂяo�����Ƃ�z�肵player1��Human�Ƃ��ď��������Aplayer2��Ai�Ƃ��ď�����
// GameOsero���ł͂P�蕪�̂ݏ������s��
OseroGame::OseroGame(JsonIO json)
    : player1(std::make_unique<Human>(osero::BLACK)),
    player2(std::make_unique<Ai>(osero::WHITE)),
    board(std::move(json.board))
{  
    if (json.hasLastMoveSet()) {
		currentPlayerPtr = player1.get(); // �����v���C���[��Human�ɐݒ�
        static_cast<Human*>(player1.get())->setLastMove(json.getLastMove());
    }
    else {
		currentPlayerPtr = player2.get(); // �����v���C���[��Human�ɐݒ�
    }
	// unique_ptr���g�p����Board�I�u�W�F�N�g���󂯎��R���X�g���N�^
}

void OseroGame::start()
{
	int centerRow = board->sizeOfBoard() / 2 - 1;
	int centerCol = board->sizeOfBoard() / 2 - 1;
    // �����z�u��ݒ�
    board->setCell(centerRow, centerCol, osero::WHITE);
    board->setCell(centerRow + 1, centerCol + 1, osero::WHITE);
    board->setCell(centerRow, centerCol + 1, osero::BLACK);
    board->setCell(centerRow + 1, centerCol, osero::BLACK);
    
    // �Q�[���J�n�̃��b�Z�[�W��\��
}

void OseroGame::changePlayer()
{
    currentPlayerPtr = (currentPlayerPtr == player1.get()) ? player2.get() : player1.get();
}

void OseroGame::endGame()
{
	// TODO: �����Ɏ����R�[�h��ǉ����܂�.
}

// �Q�[���I�[�o�[�̃`�F�b�N���s���֐�
// Board�N���X��Player�N���X���g�p���āA�Ֆʂ̏�Ԃ��m�F���A���@�肪���邩�ǂ����𔻒f���܂�
int OseroGame::checkGameOver()  
{  
    const int size = board->sizeOfBoard(); 
	int currentPlayer = this->currentPlayerPtr->getColor(); // ���݂̃v���C���[�̐F���擾
	int oppositePlayer = (currentPlayer == osero::BLACK) ? osero::WHITE : osero::BLACK;
	unsigned char continueFlag = 0; // ���s�t���O��������

    for (int row = 0; row < size; ++row) {  
        for (int col = 0; col < size; ++col) {  
            if (board->getCell(row,col) == osero::NONE && board->isLegalMove(row, col, currentPlayer)) {
                return 1; //�ݒu�ł��邽�ߑ��s 
            }  
            else if (board->getCell(row, col) == osero::NONE && board->isLegalMove(row, col, oppositePlayer)) {
				continueFlag = 1; // ����̎�ԂŐݒu�\�ȏꏊ�����邽�ߑ��s�t���O�𗧂Ă�
                continue;
            }
        }  
    }  
    if(continueFlag == 0) { // �ǂ�����ݒu�ł��Ȃ��ꍇ
        endGame(); //�I���������Ăяo��
        return 0; // �I��
    }
    else {
        changePlayer(); // �v���C���[�����
		return 2; // ���s
    }

}

void OseroGame::sendJsonForm() {
	JsonIO json;
	json.EmitJsonForm(*board,checkGameOver());
}

// ���݂ɂP�肸���s����֐�
bool OseroGame::singleRun() {

    return currentPlayerPtr->getMove(*board);
};


void OseroGame::goGame()
{
    try {
        currentPlayerPtr = this->player1.get(); // �����v���C���[��ݒ�
        while (this->checkGameOver()) {
            currentPlayerPtr->getMove(*board);
			changePlayer(); // �v���C���[�����
			// �Ֆʂ̏�Ԃ�\�����鏈���������ɋL�q
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
