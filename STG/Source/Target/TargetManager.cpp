#include "TargetManager.h"

TargetManager::TargetManager()
	: modelHandle(MV1LoadModel("./Model/OB_001_target_01_01.mv1")){
	for (int i = 0; i < targetValue; i++) {
		targetList.emplace_back(std::make_shared<Target>(modelHandle, 1));
	}
}

TargetManager::~TargetManager() {
	MV1DeleteModel(modelHandle);
}

void TargetManager::Update() {
	for (std::shared_ptr<Target> target : targetList) {
		target->Update();
	}
}

void TargetManager::Draw() {
	for (std::shared_ptr<Target> target : targetList) {
		target->Draw();
	}
}