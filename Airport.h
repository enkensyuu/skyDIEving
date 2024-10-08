#pragma once
class Airport {
	
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
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

