#pragma once
#include "Transform.h"

class WindowL
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="y"></param>
	void Initialize(float y1,float y2, float y3, float y4);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

public:
	Transform transform_[4];
	float speedY = 3.0f;
	float max_ = 0;
};
