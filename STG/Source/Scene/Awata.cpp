#include "Awata.h"

Awata::Awata()
	: SceneBase(), targetManager(std::make_unique<TargetManager>()) {

	SetCameraNearFar(0.1f, 1000.0f); 
	SetCameraPositionAndTargetAndUpVec(VGet(0, 0, 300), VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 1.0f, 0.0f));
}

Awata::~Awata() {}


void Awata::Update() {
	targetManager->Update();
}


void Awata::Draw() {
	targetManager->Draw();
	DrawFormatString(100, 100, GetColor(0, 0, 255), "ˆ¾“c");
}

void Awata::ChangeScene(std::shared_ptr<SceneBase>& current_scene) {}