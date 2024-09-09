#pragma once
#include "Transform.h"

class WindowL
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="y"></param>
	void Initialize(float y);

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
	float speedY = 3.0f;
};
