#pragma once
#include "Transform.h"

class Helicopter {

public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

public:
	static const int num_ = 4;

	Transform transform_[num_];
	
	//Yのスピード設定
	float upSpeed;
	float downSpeed;

	//ヘリが下がるタイマー
	float changeTimer[num_];

	//ヘリの画像数
	int GHandle[18];

	int count;
	float max_ = -500;

	bool isUp_[num_];
	bool isDown_[num_];
};

