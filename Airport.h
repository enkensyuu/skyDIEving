#pragma once
#include "Transform.h"

class Airport {
	
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize(float x,float y);

	/// <summary>
	/// XV
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

private:
	Transform transform_;
	int speedX;
	int speedY;
};

