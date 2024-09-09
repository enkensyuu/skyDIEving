#pragma once
#include "Transform.h"

class WindowL
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	/// <param name="y"></param>
	void Initialize(float y);

	/// <summary>
	/// XV
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

public:
	Transform transform_;
	float speedY = 3.0f;
};
