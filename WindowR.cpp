#include "WindowR.h"
#include "Dxlib.h"

void WindowR::Initialize(float y)
{
	transform_.x = 600.0f;
	transform_.y = y;
	transform_.rx = 600.0f;
	transform_.ry = 100.0f;
}

void WindowR::Update()
{
	transform_.y -= speedY;
}

void WindowR::Draw()
{
	DrawBox(transform_.x - transform_.rx, transform_.y - transform_.ry, transform_.x + transform_.rx, transform_.y + transform_.ry, GetColor(0, 0, 255), true);
}
