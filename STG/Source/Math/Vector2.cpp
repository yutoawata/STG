#include"Vector2.h"

using namespace std;

//�[���x�N�g��
const Vector2 Vector2::ZERO = Vector2(0, 0);

//�R���X�g���N�^
Vector2::Vector2() {}

//�R���X�g���N�^
Vector2::Vector2(int x_, int y_) {
	x = x_;
	y = y_;
}

//�R���X�g���N�^
Vector2::Vector2(float x_, float y_) {
	x = static_cast<int>(x_);
	y = static_cast<int>(y_);
}

//�R���X�g���N�^
Vector2::Vector2(VECTOR vector_) {
	x = static_cast<int>(vector_.x);
	y = static_cast<int>(vector_.y);
}

//���Ϗ���
float Vector2::Dot(Vector2 vec_01, Vector2 vec_02) {
	return static_cast<float>((vec_01.x * vec_02.x) + (vec_01.y * vec_02.y));
}

//�O�Ϗ���
float Vector2::Cross(Vector2 vec_01, Vector2 vec_02) {
	return static_cast<float>((vec_01.x * vec_02.y) - (vec_01.y * vec_02.x));
}

//�T�C�Y��Ԃ�
int Vector2::getSize() const {
	float vecX = static_cast<float>(x);
	float vecY = static_cast<float>(y);
	return static_cast<int>(sqrtf(vecX * vecX + vecY * vecY));
}

//���K������
Vector2 Vector2::Normalized() const {
	int size = getSize();
	return Vector2(x / size, y / size);
}

//���Z�̉��Z�q�I�[�o�[���[�h
Vector2 Vector2::operator+(const Vector2& other_) const {
	return Vector2(x + other_.x, y + other_.y);
}

//���Z�̉��Z�q�I�[�o�[���[�h
Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

//��Z�̉��Z�q�I�[�o�[���[�h
Vector2 Vector2::operator*(int value) const {
	return Vector2(x * value, y * value);
}

//���Z�̉��Z�q�I�[�o�[���[�h
Vector2 Vector2::operator/(int value) const {
	return Vector2(x / value, y / value);
}

//���Z�̉��Z�q�I�[�o�[���[�h(�񍀉��Z�q)
Vector2& Vector2::operator +=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

//���Z�̉��Z�q�I�[�o�[���[�h(�񍀉��Z�q)
Vector2& Vector2::operator -=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

//�����̉��Z�q�I�[�o�[���[�h
bool Vector2::operator ==(const Vector2& other) {
	return (x == other.x && y == other.y);
}

//�s�����̉��Z�q�I�[�o�[���[�h
bool Vector2::operator !=(const Vector2& other) {
	return (x != other.x || y != other.y);
}

//���C�u�������p�ӂ����x�N�g���N���X�ɃL���X�g
Vector2::operator VECTOR() {
	return VGet(static_cast<float>(x), static_cast<float>(y), 0.0f);
}
