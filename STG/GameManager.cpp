#include "GameManager.h"

//�R���X�g���N�^
GameManager::GameManager() {
	//�𑜓x��ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	//�t���X�N���[���ɂ���
	ChangeWindowMode(FALSE);
	isInit = DxLib_Init();

	//Z�o�b�t�@�̎g�p������
	SetUseZBuffer3D(TRUE);
	//Z�o�b�t�@�̏������݂�����
	SetWriteZBuffer3D(TRUE);
	//�}�E�X�J�[�\���̕\����ON
	SetMouseDispFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
}

//�f�X�g���N�^
GameManager::~GameManager() {
	InitSoundMem();
	DxLib_End();
}

//�Q�[�����[�v
void GameManager::Run() {
	while (!ProcessMessage() && isInit != TRUE) {

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}
		
		ClearDrawScreen();

		ScreenFlip();
	}
}