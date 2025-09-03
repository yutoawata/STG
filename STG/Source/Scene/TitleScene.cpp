#include "TitleScene.h"

TitleScene::TitleScene()
	:SceneBase() {}

TitleScene::~TitleScene() {}

void TitleScene::Update() {
	
}

void TitleScene::Draw() {
	DrawString(100, 100, "デバックシーン : あわた->1, たむら->2", GetColor(255, 255, 255));

}

SceneBase* TitleScene::ChangeScene() {
	
	if (CheckHitKey(KEY_INPUT_1)) {
		delete this;
		return new Awata();
	}
	else if (CheckHitKey(KEY_INPUT_2)) {
		delete this;
		return new Tamura();
	}

	return this;
}