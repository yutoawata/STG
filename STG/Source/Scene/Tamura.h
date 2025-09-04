#pragma once
#include "SceneBase.h"

class Tamura : public SceneBase {
public:
	Tamura();
	~Tamura();

	void Update() override;
	void Draw() override;

	void ChangeScene(std::shared_ptr<SceneBase>& current_scene) override;
};