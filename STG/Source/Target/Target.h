#pragma once
#include"../Math/Vector3.h"

class Target {
public:
	//�R���X�g���N�^]
	Target(int model_handle, int move_line_num);
	//�f�X�g���N�^
	~Target();

	void Update();
	void Draw();

private:
	Vector3 position = Vector3::ZERO;
	float moveSpeed = 1.0f;
	int moveLineNum = 0;
	int modelHandle;
	bool canHit = false;
};