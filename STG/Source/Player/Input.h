#pragma once


// 入力を受け付ける
class Input
{
public:
	Input();

	void Update();

	// 各成分のGetter
	int GetMousePosX();
	int GetMousePosY();


	// クリックしたかどうか(引数には左右のボタンを入れる)
	bool IsMouseClick(int button);

	/*
	   入力関数
	   上から
	   押している時
	   押したとき
	   離したとき
	*/
	bool IsKeyPress(int key);
	bool IsKeyPushed(int key);
	bool IsKeyReleased(int key);

private:
	bool IsKeyCheck(int key);

	char currentKeyBuffer[256]; // 現在のフレームのキーの入力情報
	char prevKeyBuffer[256]; // 1つ前のフレームのキーの入力情報

	int clickType;
	int clickButton;
	int mousePosX;
	int mousePosY;
};
