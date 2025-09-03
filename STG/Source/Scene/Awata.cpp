#include "Awata.h"

Awata::Awata()
	: SceneBase() {}

Awata::~Awata() {}


void Awata::Update() {

}


void Awata::Draw() {
	DrawFormatString(100, 100, GetColor(0, 0, 255), "ˆ¾“c");
}

SceneBase* Awata::ChangeScene() {
	return this;
}