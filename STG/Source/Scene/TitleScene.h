#pragma once
#include "Awata.h"
#include "Tamura.h"

class TitleScene : public SceneBase {
public:
	TitleScene();
	~TitleScene();

	void Update() override;
	void Draw() override;

	void ChangeScene(std::shared_ptr<SceneBase>& current_scene) override;
};