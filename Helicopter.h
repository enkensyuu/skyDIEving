#pragma once
class Helicopter {

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

	//Xの位置設定
	int posX;
	//Yの位置設定
	int posY;

	//Xの半径設定
	int radiusX;
	//Yの半径設定
	int radiusY;

	//Xのスピード設定
	int speedX;
	//Yのスピード設定
	int speedY;

	//ヘリが下がるタイマー
	float changeTimer;

	//ヘリの画像数
	int GHandle[18];

	int count;
};

