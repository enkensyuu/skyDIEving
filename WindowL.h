#pragma once
#include "Transform.h"

class WindowL
{
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="y"></param>
	void Initialize(float y);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

public:
	Transform transform_;
	float speedY = 3.0f;
};
