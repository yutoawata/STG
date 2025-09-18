#pragma once
#include "SceneBase.h"
#include "../Player/Player.h"

class Tamura : public SceneBase {
public:
	Tamura();
	~Tamura();

	void Update() override;
	void Draw() override;

	void ChangeScene(std::shared_ptr<SceneBase>& current_scene) override;
	std::unique_ptr<Player> player;
};