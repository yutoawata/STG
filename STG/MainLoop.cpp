#include "DxLib.h"
#include "GameManager.h"

//���C���֐�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	//�Q�[���Ǘ��N���X�𐶐�
	GameManager* game_manager = new GameManager();
	
	//�Q�[�����[�v����
	game_manager->Run();

	//�Q�[���Ǘ��N���X���폜
	delete game_manager;
}