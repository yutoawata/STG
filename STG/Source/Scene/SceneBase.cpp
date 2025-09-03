#include "SceneBase.h"

SceneBase::SceneBase() {}

SceneBase::~SceneBase() {}

void SceneBase::Update() {}


void SceneBase::Draw() {}

SceneBase* SceneBase::ChangeScene() {
	return this;
}