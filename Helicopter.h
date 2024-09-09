#pragma once
#include "Transform.h"

class Helicopter {

public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize(float x, float y);

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
	
	//Y�̃X�s�[�h�ݒ�
	float upSpeed;
	float downSpeed;

	//�w����������^�C�}�[
	float changeTimer;

	//�w���̉摜��
	int GHandle[18];

	int count;
	float max_ = -500;

	bool isUp_;
	bool isDown_;
};

