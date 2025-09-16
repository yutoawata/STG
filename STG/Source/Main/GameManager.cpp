#include "GameManager.h"

//コンストラクタ
GameManager::GameManager() {
	//解像度を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	// Direct3D9Ex を使用する
	SetUseDirect3DVersion(DX_DIRECT3D_9EX);

	//フルスクリーンにする
	ChangeWindowMode(TRUE);
	isBuildError = DxLib_Init();

	//Zバッファの使用を許可
	SetUseZBuffer3D(TRUE);
	//Zバッファの書き込みを許可
	SetWriteZBuffer3D(TRUE);
	//マウスカーソルの表示をON
	SetMouseDispFlag(TRUE);

	SetDrawScreen(DX_SCREEN_BACK);

	currentScene = SceneBase::DownCast<TitleScene>();
}

//デストラクタ
GameManager::~GameManager() {
	InitSoundMem();
	DxLib_End();
}

//ゲームループ
void GameManager::Run() {
	while (!ProcessMessage() && isBuildError == FALSE) {

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}
		
		ClearDrawScreen();

		currentScene->Update();

		currentScene->Draw();

		currentScene->ChangeScene(currentScene);

		ScreenFlip();
	}
}