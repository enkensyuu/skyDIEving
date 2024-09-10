#pragma once
#include "Transform.h"

class Goal
{
public:
	void Initialize(float x, float y) { transform_.x = x; transform_.y = y; transform_.rx = 600; transform_.ry = 100; }

	void Update() {
		transform_.y -= speed_; if (transform_.y <= max_ - transform_.ry)
		{
			transform_.y = max_ - transform_.ry;
		}
	}

public:
	Transform transform_;
	float speed_ = 3.0f;
	float max_ = 0;
};
