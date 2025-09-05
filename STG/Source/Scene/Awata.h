#pragma once
#include "SceneBase.h"
#include "../Target/TargetManager.h"

class Awata : public SceneBase {
public:
	Awata();
	~Awata();

	void Update() override;
	void Draw() override;

	void ChangeScene(std::shared_ptr<SceneBase>& current_scene) override;

private:
	std::unique_ptr<TargetManager> targetManager;
};