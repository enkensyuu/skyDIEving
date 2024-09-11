#pragma once
#include "Transform.h"

class Airport {
	
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
	float speedX;
	float speedY;
	bool changeL[num_];
	bool changeR[num_];
	float max_ = 0;
	int GraphL;
	int GraphR;
};

