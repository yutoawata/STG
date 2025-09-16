#include "Awata.h"

Awata::Awata()
	: SceneBase(), targetManager(std::make_unique<TargetManager>()) {
	/*
	// プログラマブルシェーダーモデル２．０が使用できない場合はエラーを表示して終了
	if (GetValidShaderVersion() < 200)
	{
		isBuildError = TRUE;
	}
	// 頂点シェーダーを読み込む
	pvoShaderHandle = LoadVertexShader("Source/Shader/SkinMesh4_DirLightVS.vso");

	// ピクセルシェーダーを読み込む
	psoShaderHandle = LoadPixelShader("Source/Shader/SkinMesh4_DirLightPS.pso");

	// 使用する頂点シェーダーをセット
	SetUseVertexShader(pvoShaderHandle);

	// 使用するピクセルシェーダーをセット
	SetUsePixelShader(psoShaderHandle);
	*/

	SetUseLighting(TRUE);
	//SetGlobalAmbientLight(GetColorF(0.3f, 0.3f, 0.3f, 1.0f));
	ChangeLightTypeDir(VGet(0.0f,0.0f,-1.0f));
	SetCameraNearFar(0.1f, 1000.0f); 
	SetCameraPositionAndTargetAndUpVec(VGet(0, 0, 200), VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 1.0f, 0.0f));
	magician = MV1LoadModel("Model/Magician.mv1");
	MV1SetPosition(magician, VGet(0.0f, 0.0f, -300.0f));
	MV1SetRotationXYZ(magician, VGet(0.0f, -DX_PI_F, 0.0f));
}

Awata::~Awata() {}

void Awata::Update() {
	targetManager->Update();
}

void Awata::Draw() {
	targetManager->Draw();
	MV1DrawModel(magician);
	DrawFormatString(100, 100, GetColor(0, 0, 255), "粟田");
}

void Awata::ChangeScene(std::shared_ptr<SceneBase>& current_scene) {}