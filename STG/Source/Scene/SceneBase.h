#pragma once
#include <memory>
#include "DxLib.h"

class SceneBase {
public:
	enum class Type {
		AWATA,
		TAMURA,
		TITLE
	};

	SceneBase();
	~SceneBase();

	//XVˆ—
	virtual void Update();
	//•`‰æˆ—
	virtual void Draw();

	virtual void ChangeScene(std::shared_ptr<SceneBase>& current_scene);

//protected:
	template<class T>
	static const std::shared_ptr<SceneBase> DownCast() {
		std::shared_ptr<T> child = std::make_shared<T>();

		return std::dynamic_pointer_cast<SceneBase>(child);
	}
};