#pragma once
#include "Transform.h"

class Player
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ����
	/// </summary>
	void Move(char* key);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���̕��̓����蔻��
	/// </summary>
	void WindowLOnCollision(float y, float ry);

	/// <summary>
	/// �E�̕��̓����蔻��
	/// </summary>
	void WindowROnCollision(float y, float ry);

	/// <summary>
	/// ��s�@�̓����蔻��
	/// </summary>
	void AirportOnCollision(float x, float rx, float y, float ry);

	/// <summary>
	/// �w���R�v�^�[�̓����蔻��
	/// </summary>
	void HelicopterOnCollision(float x, float rx, float y, float ry);

	/// <summary>
	/// �S�[���̓����蔻��
	/// </summary>
	void GoalOnCollision(float x, float rx, float y, float ry);

	const bool isGetDeth() { return isDeth_; }
	const bool isGetGoal() { return isGoal_; }

private:
	Transform transform_;
	float max_ = 1200.0f;
	float min_ = 0.0f;
	float speed_;
	float windowSpeed_;
	bool isDeth_;
	bool isGoal_;
};
