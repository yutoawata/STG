#pragma once
#include"../Math/Vector3.h"

class Target {
public:
	//コンストラクタ]
	Target(int model_handle, int move_line_num);
	//デストラクタ
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