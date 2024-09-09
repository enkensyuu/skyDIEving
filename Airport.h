#pragma once
#include "Transform.h"

class Airport {
	
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(float x,float y);

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
	float speedX;
	float speedY;
};

