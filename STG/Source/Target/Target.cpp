#include "Target.h"

Target::Target(int model_handle, int move_line_num)
	:modelHandle(model_handle), moveLineNum(move_line_num) {
	if (moveLineNum % 2 == 0) {
		moveSpeed = -moveSpeed;
	}
}

Target::~Target() {}

void Target::Update() {
	//position.x += moveSpeed;
	MV1SetPosition(modelHandle, static_cast<VECTOR>(position));
	MV1SetRotationXYZ(modelHandle, VGet(-DX_PI_F / 1.5f, 0.0f, 0.0f));
}

void Target::Draw() {
	MV1DrawModel(modelHandle);
	
	//DrawSphere3D(static_cast<VECTOR>(position), 10, 30, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
}