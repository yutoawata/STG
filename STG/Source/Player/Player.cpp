#include "Player.h"

// ヘルパー関数
inline float DegToRad(float d) { return d * M_PI / 180.0f; }
inline float RadToDeg(float r) { return r * 180.0f / M_PI; }

/* 
    カメラの前方向を求める
    yawRad = 左右の角度(ラジアン) マウスを左右に動かしたときの回転に使う
	pitchRad = 上下の角度(ラジアン) マウスを上下に動かしたときの回転に使う
*/
static Vector3 MakeForward(float yawRad, float pitchRad) {
	float cy = cosf(yawRad), sy = sinf(yawRad);
	float cp = cosf(pitchRad), sp = sinf(pitchRad);
	return Vector3(sy * cp, sp, cy * cp).Normalized();
}

// 前方向から右方向を求める
static Vector3 MakeRight(const Vector3& forward) {
	Vector3 up(0,1,0);
	return Vector3::Cross(up, forward).Normalized();
}


// 初期化
Player::Player() {
	speed = 0.0f;
	posX = 0.0f;
	posY = 0.0f;
	posZ = 0.0f;
	rotationX = 0.0f;
	rotationY = 0.0f;
	rotationZ = 0.0f;
	mouseSens = 0.0025f;
	prevMousePosX = 0;
    prevMousePosY = 0;
	mouseInited = false;
	isActive = false;

	SetMouseDispFlag(false); // マウス非表示

}

Player::~Player(){}

void Player::Update() {
	input.Update();

	ControlleCamera(); // マウスでyaw,pitchを更新しつつカメラ反映
	InputMove(); // WASDをforward,rightで移動
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

	// 水平成分のみ
	forward.y = 0.0f;
	if (forward != Vector3::ZERO) forward.Normalized();
	right = MakeRight(forward);
	right.Normalized();

	Vector3 wish = right * vecX + forward * vecZ;
	if (wish != Vector3::ZERO) wish = wish.Normalized();

	// ---- Δt を GetNowCount で計算する ----
	static int prevTime = GetNowCount();
	int nowTime = GetNowCount();
	float dt = (nowTime - prevTime) / 1000.0f; // ミリ秒差を秒に変換
	prevTime = nowTime;

	Vector3 delta = wish * (speed * dt);

	posX += delta.x;
	posZ += delta.z;
}

void Player::ControlleCamera() {
	// 画面サイズから中央を算出
	int sw, sh, cb;
	GetScreenState(&sw, &sh, &cb);
	const int cx = sw / 2;
	const int cy = sh / 2;

	// 現在のマウス座標
	int mx, my;
	GetMousePoint(&mx, &my);

	//　中央との差分 = 今フレームの移動量
	int dx = mx - cx;
	int dy = my - cy;

	// 視点回転に反映
	rotationX += dx * mouseSens; // yaw(左右)
	rotationY += -dy * mouseSens; // pitch(上下　方向を逆にしたいなら符号を触る) 

	// ピッチ制限
	const float limit = 1.4f;
	if (rotationX > limit) rotationX = limit;
	if (rotationX < -limit) rotationX = -limit;
	// 使い終わったら中央へ戻す
	SetMousePoint(cx, cy);

	//カメラ位置と向きを反映
	float camrahight = 1.5f; // カメラの高さ
	Vector3 camPos(posX, posY + camrahight, posZ);
	forward = MakeForward(rotationY, rotationX); // 前を作る
	Vector3 camTar = camPos + forward;

	SetCameraPositionAndTarget_UpVecY((VECTOR)camPos, (VECTOR)camTar);
}
