#pragma once
class Airport {
	
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
	int posX;
	int posY;
	int radiusX;
	int radiusY;
	int speedX;
	int speedY;
};

