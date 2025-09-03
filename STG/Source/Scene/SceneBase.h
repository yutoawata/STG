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

	//�X�V����
	virtual void Update();
	//�`�揈��
	virtual void Draw();

	virtual SceneBase* ChangeScene();
};