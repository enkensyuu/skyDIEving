#pragma once
#include "Transform.h"

class WindowL
{
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="y"></param>
	void Initialize(float y1,float y2, float y3, float y4);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

public:
	static const int num_ = 4;
	Transform transform_[num_];
	float speedY = 3.0f;
	float max_ = 0;

	//�摜��
	int GHandle[7];

	int count;
};
