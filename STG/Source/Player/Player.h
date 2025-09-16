#pragma once
#include "Dxlib.h"
#include "../Math/Vector3.h"
#include "Input.h"


class Player
{
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	// 更新
	void Update();
	// 描画
	void Draw();

private:
	void InputMove();


	Input input;
	// 移動速度
	float speed;
	// 位置座標
	float posX;
	float posY;
	float posZ;
	// 回転
	float rotationX;
	float rotationY;
	float rotationZ;
	// 生存フラグ
	bool isActive;
};

