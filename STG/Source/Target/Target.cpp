#include "Target.h"

Target::Target(Vector3 position_, int origin_handle, int move_line_num)
	: position(position_), modelHandle(MV1DuplicateModel(origin_handle)), moveLineNum(move_line_num + 1) {
	if (moveLineNum % 2 == 0) {
		moveSpeed = -moveSpeed;
	}

	int lineHight = move_line_num * move_line_num;

	if (lineHight < 0) {
		lineHight = 0;
	}

	position.y += correctionValue * lineHight;
	position.z -= correctionValue * lineHight;

	MV1SetupCollInfo(modelHandle);
}

Target::~Target() {}

void Target::Update() {
	position.x += moveSpeed;

	if (position.x >= moveLimit || position.x <= -moveLimit) {
		moveSpeed = -moveSpeed;
	}

	MV1RefreshCollInfo(modelHandle);
	MV1SetPosition(modelHandle, static_cast<VECTOR>(position));
	MV1SetRotationXYZ(modelHandle, VGet(-DX_PI_F / 2.0f, 0.0f, 0.0f));
}

void Target::Draw() {
	MV1DrawModel(modelHandle);
}