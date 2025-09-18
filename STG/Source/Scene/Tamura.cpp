#include "Tamura.h"


Tamura::Tamura()
	: SceneBase(), player(std::make_unique<Player>()) {
	
}

Tamura::~Tamura() {}

void Tamura::Update() {
	player->Update();
}


void Tamura::Draw() {
	player->Draw();
	DrawSphere3D(VGet(0,0,0), 10, 10, GetColor(255, 255, 255), GetColor(255,255,255), true);
}

void Tamura::ChangeScene(std::shared_ptr<SceneBase>& current_scene) {}