#include "TargetManager.h"

TargetManager::TargetManager()
	: modelHandle(MV1LoadModel("./Model/OB_001_target_01_01.mv1")){
	for (int i = 0; i < targetValue; i++) {
		Vector3 position = Vector3::ZERO;
		int lineNum = (i % lineValue) + 1;
		switch (lineNum + 1) {
		case 1:
		case 3:
			position.y = 10.0f;
			break;
		case 2:
			position.y = -10.0f;
			break;
		}
		targetList.emplace_back(std::make_shared<Target>(position, modelHandle, i % lineValue));
	}
}

TargetManager::~TargetManager() {
	MV1DeleteModel(modelHandle);
}

void TargetManager::Update() {

	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		lineStart.x -= 1.0f;
		lineEnd.x -= 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		lineStart.x += 1.0f;
		lineEnd.x += 1.0f;

	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		lineStart.y += 1.0f;
		lineEnd.y += 1.0f;

	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		lineStart.y -= 1.0f;
		lineEnd.y -= 1.0f;

	}

	for (std::shared_ptr<Target> target : targetList) {
		target->Update();
		DrawLine3D(static_cast<VECTOR>(lineStart), static_cast<VECTOR>(lineEnd), GetColor(255, 0, 0));

		MV1_COLL_RESULT_POLY collResult = MV1CollCheck_Line(target->modelHandle, -1, static_cast<VECTOR>(lineStart), static_cast<VECTOR>(lineEnd));

		unsigned int color = GetColor(255, 255, 255);

		if (collResult.HitFlag) {
			switch (collResult.FrameIndex) {
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
			DrawFormatString(10, 20, color, "%d", collResult.FrameIndex);
			DrawCircle(10, 10, 10, color);
		}
	}
}

void TargetManager::Draw() {
	for (std::shared_ptr<Target> target : targetList) {
		target->Draw();
	}
}