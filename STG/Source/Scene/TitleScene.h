#pragma once
#include "Awata.h"
#include "Tamura.h"

class TitleScene : public SceneBase {
public:
	TitleScene();
	~TitleScene();

	void Update() override;
	void Draw() override;

	SceneBase* ChangeScene() override;
};