#include "Player.h"

// 初期化
Player::Player() {
	speed = 0.0f;
	posX = 0.0f;
	posY = 0.0f;
	posZ = 0.0f;
	rotationX = 0.0f;
	rotationY = 0.0f;
	rotationZ = 0.0f;
	isActive = false;
}

Player::~Player(){}

void Player::Update() {
	input.Update();
	InputMove();
}

void Player::Draw() {

}


void Player::InputMove() {
	float vecX = 0.0f;
	float vecZ = 0.0f;
	if (input.IsKeyPress(KEY_INPUT_W)) vecZ += 1.0f;
	if (input.IsKeyPress(KEY_INPUT_S)) vecZ -= 1.0f;
	if (input.IsKeyPress(KEY_INPUT_A)) vecX -= 1.0f;
	if (input.IsKeyPress(KEY_INPUT_D)) vecX += 1.0f;

	// 入力ベクトルをVector3化
	Vector3 moveVec(vecX, 0, vecZ);

	// 長さが0でなければ正規化
	if (moveVec != Vector3::ZERO) {
		moveVec = moveVec.Normalized(); // 長さを1にする
	}

	// 速度をかける
	posX += moveVec.x * speed;
	posY += moveVec.y * speed;
	posZ += moveVec.z * speed;
}

