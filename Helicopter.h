#pragma once
class Helicopter {

public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

private:

	//X�̈ʒu�ݒ�
	int posX;
	//Y�̈ʒu�ݒ�
	int posY;

	//X�̔��a�ݒ�
	int radiusX;
	//Y�̔��a�ݒ�
	int radiusY;

	//X�̃X�s�[�h�ݒ�
	int speedX;
	//Y�̃X�s�[�h�ݒ�
	int speedY;

	//�w����������^�C�}�[
	float changeTimer;

	//�w���̉摜��
	int GHandle[18];

	int count;
};

