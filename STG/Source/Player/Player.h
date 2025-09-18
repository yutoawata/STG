#pragma once
#include "Dxlib.h"
#include <numbers>
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
	void ControlleCamera();


	Input input;
	Vector3 forward; // カメラの前方向
	Vector3 right; // カメラの右方向
	// 移動速度
	float speed;
	// 位置座標
	float posX, posY, posZ;
	// 回転
	float rotationX, rotationY, rotationZ; // pitch, yaw, roll

	// カメラ用
	float mouseSens; // マウス感度
	float prevMousePosX, prevMousePosY;
	bool mouseInited;
	// 生存フラグ
	bool isActive;
};

