#pragma once
#include "SceneBase.h"

class Tamura : public SceneBase {
public:
	Tamura();
	~Tamura();

	void Update() override;
	void Draw() override;

	SceneBase* ChangeScene() override;
};