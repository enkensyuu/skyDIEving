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

private:
	Transform transform_;
	int speedX;
	int speedY;
};

