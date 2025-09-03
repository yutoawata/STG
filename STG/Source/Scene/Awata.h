#pragma once
#include "SceneBase.h"

class Awata : public SceneBase {
public:
	Awata();
	~Awata();

	void Update() override;
	void Draw() override;

	SceneBase* ChangeScene() override;
};