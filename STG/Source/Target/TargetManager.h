#pragma once
#include <memory>
#include <vector>
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
	int targetValue = 3;
	int lineValue = 3;
	Vector3 lineStart = Vector3(0.0f, 1.0f, 10.0f);
	Vector3 lineEnd = Vector3(0.0f, 1.0f, -10.0f);
};