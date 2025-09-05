#include "Target.h"

Target::Target(int move_line_num)
	: moveLineNum(move_line_num) {
	if (moveLineNum % 2 == 0) {
		moveSpeed = -moveSpeed;
	}
}

Target::~Target() {}

void Target::Update() {
	position.x += moveSpeed;
}

void Target::Draw() {
	DrawSphere3D(static_cast<VECTOR>(position), 100, 30, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
}