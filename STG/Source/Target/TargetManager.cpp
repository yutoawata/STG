#include "TargetManager.h"

TargetManager::TargetManager() {
	for (int i = 0; i < targetValue; i++) {
		targetList.emplace_back(std::make_shared<Target>(1));
	}
}

TargetManager::~TargetManager() {}

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