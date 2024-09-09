#include "Dxlib.h"
#include "helicopter.h"

void Helicopter::Initialize(float x, float y) {
	transform_.x = x;
	transform_.y = y;
	transform_.rx = 140;
	transform_.ry = 60;
	upSpeed = 8;
	downSpeed = 3;
	changeTimer = 60.0f;
	isUp_ = true;
	isDown_ = false;

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
	DrawGraph(transform_.x - transform_.rx, transform_.y - transform_.ry, GHandle[count], TRUE);
}
