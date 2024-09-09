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
	void WindowLOnCollision(float y,float ry);

	/// <summary>
	/// �E�̕��̓����蔻��
	/// </summary>
	void WindowROnCollision(float y, float ry);

private:
	Transform transform_;
	float max_ = 1200.0f;
	float min_ = 0.0f;
	float speed_;
	float windowSpeed_;
};
