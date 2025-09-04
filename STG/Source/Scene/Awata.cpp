#include "Awata.h"

Awata::Awata()
	: SceneBase() {}

Awata::~Awata() {}


void Awata::Update() {

}


void Awata::Draw() {
	DrawFormatString(100, 100, GetColor(0, 0, 255), "ˆ¾“c");
}

void Awata::ChangeScene(std::shared_ptr<SceneBase>& current_scene) {}