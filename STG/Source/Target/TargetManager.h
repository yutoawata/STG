#pragma once
#include <memory>
#include <vector>
#include "DxLib.h"
#include "Target.h"

class TargetManager {
public:
	TargetManager();
	~TargetManager();

	void Update();
	void Draw();

private:
	const int modelHandle;
	std::vector<std::shared_ptr<Target>> targetList;
	int targetValue = 1;
};