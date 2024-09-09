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

private:
	Transform transform_;
	int speedX;
	int speedY;
};

