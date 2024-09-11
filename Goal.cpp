#include "Goal.h"

void Goal::Initialize(float y)
{
	transform_.x = 600;
	transform_.y = y; 
	transform_.rx = 600;
	transform_.ry = 100;
}

void Goal::Update()
{
	transform_.y -= speed_;
	if (transform_.y <= max_ - transform_.ry)
	{
		transform_.y = max_ - transform_.ry;
	}
}
