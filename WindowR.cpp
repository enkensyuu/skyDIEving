#include "WindowR.h"
#include "Dxlib.h"

void WindowR::Initialize(float y1, float y2, float y3, float y4)
{
	for (int i = 0; i < _countof(transform_); i++)
	{
		transform_[i].x = 600.0f;
		transform_[0].y = y1;
		transform_[1].y = y2;
		transform_[2].y = y3;
		transform_[3].y = y4;
		transform_[i].rx = 600.0f;
		transform_[i].ry = 100.0f;
	}
	count = 0;

	LoadDivGraph("Resources/windLeft.png", 7, 7, 1, 1200, 200, GHandle);
}

void WindowR::Update()
{
	count++;
	if (count == 18) {
		count = 0;
	}
	for (int i = 0; i < _countof(transform_); i++)
	{
		transform_[i].y -= speedY;
		if (transform_[i].y <= max_ - transform_[i].ry)
		{
			transform_[i].y = max_ - transform_[i].ry;
		}
	}
}

void WindowR::Draw()
{
	for (int i = 0; i < _countof(transform_); i++)
	{
		DrawGraph(transform_[i].x - transform_[i].rx, transform_[i].y - transform_[i].ry, GHandle[count], TRUE);
	}
}
