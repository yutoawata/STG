#include "Dxlib.h"
#include <Windows.h>
#include "Input.h"

// 初期化
Input::Input() {
	ZeroMemory(currentKeyBuffer, sizeof(char) * 256);
	ZeroMemory(prevKeyBuffer, sizeof(char) * 256);

	clickButton = 0;
	clickType = 0;
	mousePosX = 0;
	mousePosY = 0;
}

bool Input::IsKeyCheck(int key) {
	if (key >= 0 && key < 256) {
		return true;
	}

	return false;
}


// 更新関数
void Input::Update() {
	// キー情報の更新前に今のキー情報を1F前の情報として保存する
	memcpy(prevKeyBuffer, currentKeyBuffer, sizeof(char) * 256);

	// キーの更新
	GetHitKeyStateAll(currentKeyBuffer);

	// マウスの更新
	GetMouseInputLog2(&clickButton, &mousePosX, &mousePosY, &clickType);
}

int Input::GetMousePosX() {
	return mousePosX;
}

int Input::GetMousePosY() {
	return mousePosY;
}

bool Input::IsMouseClick(int button) {
	if (clickButton == button &&
		clickType == MOUSE_INPUT_LOG_DOWN) {
		return true;
	}
	return false;
}


bool Input::IsKeyPress(int key) {
	if (!IsKeyCheck(key)) {
		return false;
	}

	// 1つ前のフレームと現在のフレームでキーが押されている
	if (prevKeyBuffer[key] == 1 &&
		currentKeyBuffer[key] == 1) {
		return true;
	}

	return false;
}

bool Input::IsKeyPushed(int key) {
	if (!IsKeyCheck(key)) {
		return false;
	}

	//　指定されたキーが1つ前のフレームでは押されておらず、現在のフレームで押されている
	if (prevKeyBuffer[key] == 0 &&
		currentKeyBuffer[key] == 1) {
		return true;
	}
	return false;
}

bool Input::IsKeyReleased(int key) {
	if (!IsKeyCheck(key)) {
		return false;
	}

	// 指定されたキーが1つ前のフレームでは押されており、現在のフレームでは押されていない
	if (prevKeyBuffer[key] == 1 &&
		currentKeyBuffer[key] == 0) {
		return true;
	}

	return false;
}