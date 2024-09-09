#include "WindowL.h"
#include "Dxlib.h"

void WindowL::Initialize(float y1, float y2, float y3, float y4)
{
	for (int i = 0; i < _countof(transform_); i++)
	{
		transform_[i].x = 600.0f;
		transform_[0].y = y1;
		transform_[1].y = y1;
		transform_[2].y = y1;
		transform_[3].y = y1;
		transform_[i].rx = 600.0f;
		transform_[i].ry = 100.0f;
	}
}

void WindowL::Update()
{
	for (int i = 0; i < _countof(transform_); i++)
	{
		transform_[i].y -= speedY;
		if (transform_[i].y <= max_ - transform_[i].ry)
		{
			transform_[i].y = max_ - transform_[i].ry;
		}
	}
}

void WindowL::Draw()
{
	for (int i = 0; i < _countof(transform_); i++)
	{
		DrawBox(transform_[i].x - transform_[i].rx, transform_[i].y - transform_[i].ry, transform_[i].x + transform_[i].rx, transform_[i].y + transform_[i].ry, GetColor(0, 255, 0), true);
	}

}
