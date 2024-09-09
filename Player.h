#pragma once
#include "Transform.h"

class Player
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// ‹““®
	/// </summary>
	void Move(char* key);

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

	/// <summary>
	/// ¶‚Ì•—‚Ì“–‚½‚è”»’è
	/// </summary>
	void WindowLOnCollision(float y,float ry);

	/// <summary>
	/// ‰E‚Ì•—‚Ì“–‚½‚è”»’è
	/// </summary>
	void WindowROnCollision(float y, float ry);

private:
	Transform transform_;
	float max_ = 1200.0f;
	float min_ = 0.0f;
	float speed_;
	float windowSpeed_;
};
