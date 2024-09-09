#include "Dxlib.h"
#include "helicopter.h"

void Helicopter::Initialize(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	for (int i = 0; i < _countof(transform_); i++)
	{
		transform_[0].x = x1;
		transform_[0].y = y1;
		transform_[1].x = x2;
		transform_[1].y = y2;
		transform_[2].x = x3;
		transform_[2].y = y3;
		transform_[3].x = x4;
		transform_[3].y = y4;
		transform_[i].rx = 140;
		transform_[i].ry = 60;
		upSpeed = 8;
		downSpeed = 3;
		changeTimer[0] = 60.0f;
		isUp_[0] = true;
		isDown_[0] = false;
	}

	count = 0;

	LoadDivGraph("Resources/helicopterGIF.png", 18, 18, 1, 280, 120, GHandle);
}

void Helicopter::Update() {
	count++;
	changeTimer--;
	if (count == 18) {
		count = 0;
	}

	if (changeTimer < 0 && !isUp_)
	{
		isUp_ = true;
		isDown_ = false;
		changeTimer = 60.0f;
	}
	else if (changeTimer < 0 && !isDown_)
	{
		isUp_ = false;
		isDown_ = true;
		changeTimer = 60.0f;
	}
	if (isUp_)
	{
		transform_.y -= upSpeed;
	}
	else if (isDown_)
	{
		transform_.y += downSpeed;
	}



	if (transform_.y <= max_ - transform_.ry)
	{
		transform_.y = max_ - transform_.ry;
	}
}

void Helicopter::Draw() {
	for (int i = 0; i < _countof(transform_); i++)
	{
		DrawGraph(transform_[i].x - transform_[i].rx, transform_[i].y - transform_[i].ry, GHandle[count], TRUE);
	}
}
