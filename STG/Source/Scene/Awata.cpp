#include "Awata.h"

Awata::Awata()
	: SceneBase(), targetManager(std::make_unique<TargetManager>()), player(std::make_unique<Player>()) {
	
	// プログラマブルシェーダーモデル２．０が使用できない場合はエラーを表示して終了
	if (GetValidShaderVersion() < 200)
	{
		//isBuildError = TRUE;
	}
	// 頂点シェーダーを読み込む
	pvoShaderHandle = LoadVertexShader("Source/Shader/SkinMesh4_DirLightVS.vso");

	// ピクセルシェーダーを読み込む
	psoShaderHandle = LoadPixelShader("Source/Shader/SkinMesh4_DirLightPS.pso");

	// 使用する頂点シェーダーをセット
	SetUseVertexShader(pvoShaderHandle);

	// 使用するピクセルシェーダーをセット
	SetUsePixelShader(psoShaderHandle);
	

	SetUseLighting(FALSE);
	ChangeLightTypeDir(VGet(0.0f,0.0f,-1.0f));
}

Awata::~Awata() {}

void Awata::Update() {
	player->Update();
	targetManager->Update();
}

void Awata::Draw() {
	player->Draw();
	targetManager->Draw();
	DrawFormatString(100, 100, GetColor(0, 0, 255), "粟田");
}

void Awata::ChangeScene(std::shared_ptr<SceneBase>& current_scene) {}