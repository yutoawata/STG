#include "TitleScene.h"

TitleScene::TitleScene()
	:SceneBase() {}

TitleScene::~TitleScene() {}

void TitleScene::Update() {
	
}

void TitleScene::Draw() {
	DrawString(100, 100, "�f�o�b�N�V�[�� : ���킽->1, ���ނ�->2", GetColor(255, 255, 255));

}

void TitleScene::ChangeScene(std::shared_ptr<SceneBase>& current_scene) {
	
	if (CheckHitKey(KEY_INPUT_1)) {
		current_scene = SceneBase::DownCast<Awata>();
	}
	else if (CheckHitKey(KEY_INPUT_2)) {
		current_scene = SceneBase::DownCast<Tamura>();
	}
}