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

	for (const std::shared_ptr<Target> target : targetList) {
		target->Update();
		std::unique_ptr<Collider<Target>> collider = std::make_unique<Collider<Target>>(lineStart, lineEnd);
		DrawLine3D(static_cast<VECTOR>(lineStart), static_cast<VECTOR>(lineEnd), GetColor(255, 0, 0));

		MV1_COLL_RESULT_POLY collResult
			= MV1CollCheck_Line(target->COLLIDER->modelHandle,
				-1,
				static_cast<VECTOR>(collider->start),
				static_cast<VECTOR>(collider->end));

		if (collResult.HitFlag) {
			target->COLLIDER->collisionFunc(collResult);
		}
	}
}

void TargetManager::Draw() {
	for (std::shared_ptr<Target> target : targetList) {
		target->Draw();
	}
}