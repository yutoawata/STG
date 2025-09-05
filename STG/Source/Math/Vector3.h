#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include"DxLib.h"

struct Vector3 {
	//�����o�֐�

	//�R���X�g���N�^
	Vector3();
	//�O�����x�N�g���p�R���X�g���N�^
	Vector3(float x_, float y_, float z_);

	Vector3(VECTOR vector_);


	//���όv�Z
	static float Dot(Vector3 vec_01, Vector3 vec_02);
	//�O�όv�Z
	static Vector3 Cross(Vector3 vec_01, Vector3 vec_02);
	//�P�ʃx�N�g����Ԃ�
	Vector3 Normalized() const;
	//�T�C�Y��Ԃ�
	float getSize() const { return sqrtf(x * x + y * y + z * z); }

	//���Z�q�I�[�o�[���[�h
	
	//Vector�N���X���m�̉��Z
	Vector3 operator +(const Vector3& other) const;
	//Vector�N���X���m�̌��Z
	Vector3 operator -(const Vector3& other) const;
	//�e�v�f�ւ̏�Z
	Vector3 operator *(float value) const;
	//�e�v�f�ւ̏��Z
	Vector3 operator /(float value) const;
	//Vector�N���X���m�̉��Z
	Vector3& operator +=(const Vector3& other);
	//Vector�N���X���m�̌��Z
	Vector3& operator -=(const Vector3& other);
	//Vector�N���X���m�̉��Z
	Vector3& operator *=(float value);
	//Vector�N���X���m�̌��Z
	Vector3& operator /=(float value);
	//Vector�N���X���m�̓�����r
	bool operator ==(const Vector3& other);
	//Vector�N���X���m�̕s������r
	bool operator !=(const Vector3& other);
	//DX���C�u�����̃x�N�g���N���X�ւ̃L���X�g
	operator VECTOR() const;
	
	//�����o�萔
	static const Vector3 ZERO;//�[���x�N�g��

	//�����o�ϐ�
	float x = 0.0f;//X����
	float y = 0.0f;//Y����
	float z = 0.0f;//Z����
};