#pragma once
#include"../Math/Vector3.h"
#include "../Collider/Collider.h"

class Target {
public:
	//コンストラクタ]
	Target(Vector3 position_, int origin_handle, int move_line_num);
	//デストラクタ
	~Target();

	void Update();
	void Draw();
	static void Collision(MV1_COLL_RESULT_POLY collisionResult);

	const int MODEL_HANDLE;
	const std::unique_ptr<Collider<Target>> COLLIDER;
private:
	Vector3 position = Vector3::ZERO;
	float moveSpeed = 1.0f;
	float moveLimit = 200.0f;
	float correctionValue = 20.0f;
	int moveLineNum = 0;
	bool canHit = false;
};