#pragma once
#include "SceneBase.h"

class Awata : public SceneBase {
public:
	Awata();
	~Awata();

	void Update() override;
	void Draw() override;

	void ChangeScene(std::shared_ptr<SceneBase>& current_scene) override;
};