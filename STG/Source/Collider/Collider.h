#pragma once
#include <memory>
#include "DxLib.h"
#include "../Math/Vector3.h"

template<class T>
struct Collider {
	
	//コンストラクタ

	//レイコライダーのコンストラクタ
	Collider(const Vector3& start_, const Vector3& end_)
		: start(start_), end(end_), modelHandle(NULL),
		  collisionFunc([](MV1_COLL_RESULT_POLY collisionResult) { T::Collision(collisionResult); }) {}
	//メッシュコライダーのコンストラクタ
	Collider(const int model_handle)
		: start(Vector3::ZERO), end(Vector3::ZERO), modelHandle(model_handle),
		collisionFunc([](MV1_COLL_RESULT_POLY collisionResult) { T::Collision(collisionResult); }) {}

	//メンバ定数
	const Vector3& start;		//線分の始点座標
	const Vector3& end;			//線分の終点座標
	const int modelHandle = 0;	//当たり判定メッシュのハンドル
	void (*const collisionFunc)(MV1_COLL_RESULT_POLY collisionResult) = nullptr;//衝突時の処理の関数ポインタ
};