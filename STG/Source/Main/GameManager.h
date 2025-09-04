#pragma once
#include <memory>
#include "DxLib.h"
#include "..\Scene\TitleScene.h"

class GameManager {
	//�����o�֐�
public:
	//�R���X�g���N�^
	GameManager();
	//�f�X�g���N�^
	~GameManager();

	//�Q�[�����[�v����
	void Run();

	//�����o�萔
private:
	//�Q�[���E�B���h�E�ݒ�萔--------------
	static const int SCREEN_WIDTH = 1920;	//�Q�[���E�B���h�E�̉���
	static const int SCREEN_HEIGHT = 1080;	//�Q�[���E�B���h�E�̏c��
	static const int SCREEN_COLOR = 32;		//�Q�[���E�B���h�E�̃J���[�r�b�g

	std::shared_ptr<SceneBase> currentScene;

	//�����o�ϐ�
	int isInit = FALSE;					//�Q�[���̏����ݒ芮���t���O
	/*
		���C�u���������ݒ�֐��uInit()�v�̌��ʂ�int�^�ŕԂ��Ă��邽��
		bool�^�ł͂Ȃ��Aint�^�ɂ��Ă��܂��B
	*/
};