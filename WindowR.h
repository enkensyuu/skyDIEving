#pragma once
#include "Transform.h"

class WindowR
{
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="y"></param>
	void Initialize(float y1,float y2,float y3,float y4);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

public:
	Transform transform_[4];
	float speedY = 3.0f;
	float max_ = 0;
};

