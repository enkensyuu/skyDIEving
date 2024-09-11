#pragma once
#include "Transform.h"

class Goal
{
public:
	void Initialize(float y);

	void Update();

public:
	Transform transform_;
	float speed_ = 3.0f;
	float max_ = 0;
};
