#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "DxLib.h"

struct Vector2 {
	//�����o�֐�
	
	//�R���X�g���N�^
	Vector2();
	//�񎟌��x�N�g���p�R���X�g���N�^
	Vector2(int x_, int y_);
	Vector2(float x_, float y_);
	
	Vector2(VECTOR vector_);


	//���όv�Z
	static float Dot(Vector2 vec_01, Vector2 vec_02);
	//�O�όv�Z
	static float Cross(Vector2 vec_01, Vector2 vec_02);
	//�P�ʃx�N�g����Ԃ�
	Vector2 Normalized() const;
	//�T�C�Y��Ԃ�
	int getSize() const;

	//���Z�q�I�[�o�[���[�h

	//Vector�N���X���m�̉��Z
	Vector2 operator +(const Vector2& other) const;
	//Vector�N���X���m�̌��Z
	Vector2 operator -(const Vector2& other) const;
	//�e�v�f�ւ̏�Z
	Vector2 operator *(int value) const;
	//�e�v�f�ւ̏��Z
	Vector2 operator /(int value) const;
	//Vector�N���X���m�̉��Z
	Vector2& operator +=(const Vector2& other);
	//Vector�N���X���m�̌��Z
	Vector2& operator -=(const Vector2& other);
	//Vector�N���X���m�̓�����r
	bool operator ==(const Vector2& other);
	//Vector�N���X���m�̕s������r
	bool operator !=(const Vector2& other);
	//DX���C�u�����̃x�N�g���N���X�ւ̃L���X�g
	operator VECTOR();

	//�����o�萔
	static const Vector2 ZERO;//�[���x�N�g��

	//�����o�ϐ�
	int x = 0;//X����
	int y = 0;//Y����
};