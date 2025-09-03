#pragma once
#include "DxLib.h"

class SceneBase {
public:
	enum class Type {
		AWATA,
		TAMURA,
		TITLE
	};

	SceneBase();
	~SceneBase();

	//XVˆ—
	virtual void Update();
	//•`‰æˆ—
	virtual void Draw();

	virtual SceneBase* ChangeScene();
};