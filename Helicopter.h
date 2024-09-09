#pragma once
#include "Transform.h"

class Helicopter {

public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(float x, float y);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

public:
	Transform transform_;
	
	//Yのスピード設定
	float upSpeed;
	float downSpeed;

	//ヘリが下がるタイマー
	float changeTimer;

	//ヘリの画像数
	int GHandle[18];

	int count;
	float max_ = -500;

	bool isUp_;
	bool isDown_;
};

