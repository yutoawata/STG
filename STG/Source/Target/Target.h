#pragma once
#include"../Math/Vector3.h"

class Target {
public:
	//コンストラクタ]
	Target(Vector3 position_, int origin_handle, int move_line_num);
	//デストラクタ
	~Target();

	void Update();
	void Draw();

	const int modelHandle;
	const Collider shareCollider;
private:
	Collider* collider;
	Vector3 position = Vector3::ZERO;
	float moveSpeed = 1.0f;
	float moveLimit = 200.0f;
	float correctionValue = 20.0f;
	int moveLineNum = 0;
	bool canHit = false;
};