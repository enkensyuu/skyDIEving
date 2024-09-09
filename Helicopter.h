#pragma once
#include "Transform.h"

class Helicopter {

public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

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
	
	//Y�̃X�s�[�h�ݒ�
	float upSpeed;
	float downSpeed;

	//�w����������^�C�}�[
	float changeTimer[num_];

	//�w���̉摜��
	int GHandle[18];

	int count;
	float max_ = -500;

	bool isUp_[num_];
	bool isDown_[num_];
};

