#pragma once
#include "Transform.h"

class Airport {
	
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(float x,float y);

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
	float speedX;
	float speedY;
	float max_ = 0;
};

