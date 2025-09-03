#include "GameManager.h"

//コンストラクタ
GameManager::GameManager() {
	//解像度を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	//フルスクリーンにする
	ChangeWindowMode(FALSE);
	isInit = DxLib_Init();

	//Zバッファの使用を許可
	SetUseZBuffer3D(TRUE);
	//Zバッファの書き込みを許可
	SetWriteZBuffer3D(TRUE);
	//マウスカーソルの表示をON
	SetMouseDispFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
}

//デストラクタ
GameManager::~GameManager() {
	InitSoundMem();
	DxLib_End();
}

//ゲームループ
void GameManager::Run() {
	while (!ProcessMessage() && isInit != TRUE) {

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}
		
		ClearDrawScreen();

		ScreenFlip();
	}
}