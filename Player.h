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
	/// <param name="key"></param>
	void Move(char* key);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

private:
	Transform transform_;
	float max_ = 1200.0f;
	float min_ = 0.0f;
	float speed_;
};
