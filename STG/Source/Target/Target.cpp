#include "Target.h"

Target::Target(Vector3 position_, int origin_handle, int move_line_num)
	: MODEL_HANDLE(MV1DuplicateModel(origin_handle)), COLLIDER(std::make_unique<Collider<Target>>(MODEL_HANDLE)),
	  position(position_), moveLineNum(move_line_num + 1) {
	if (moveLineNum % 2 == 0) {
		moveSpeed = -moveSpeed;
	}

	int lineHight = move_line_num * move_line_num;

	if (lineHight < 0) {
		lineHight = 0;
	}

	position.y += correctionValue * lineHight;
	position.z -= correctionValue * lineHight;

	MV1SetupCollInfo(MODEL_HANDLE);
}

Target::~Target() {}

void Target::Update() {
	position.x += moveSpeed;

	if (position.x >= moveLimit || position.x <= -moveLimit) {
		moveSpeed = -moveSpeed;
	}

	MV1RefreshCollInfo(MODEL_HANDLE);
	MV1SetPosition(MODEL_HANDLE, static_cast<VECTOR>(position));
	MV1SetRotationXYZ(MODEL_HANDLE, VGet(-DX_PI_F / 2.0f, 0.0f, 0.0f));
}

void Target::Draw() {
	MV1DrawModel(MODEL_HANDLE);
}

void Target::Collision(MV1_COLL_RESULT_POLY collisionResult) {
	unsigned int color = GetColor(255, 255, 255);

	switch (collisionResult.FrameIndex) {
	case 2:
		color = GetColor(255, 0, 0);
		break;
	case 3:
		color = GetColor(0, 255, 0);
		break;
	case 4:
		color = GetColor(0, 0, 255);
		break;
	}
	DrawFormatString(10, 20, color, "%d", collisionResult.FrameIndex);
	DrawCircle(10, 10, 10, color);
}