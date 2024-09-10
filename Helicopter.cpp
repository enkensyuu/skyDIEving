#include "Dxlib.h"
#include "helicopter.h"

void Helicopter::Initialize(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	for (int i = 0; i < _countof(transform_); i++)
	{
		transform_[i].rx = 140;
		transform_[i].ry = 60;
	}
	transform_[0].x = x1;
	transform_[0].y = y1;
	transform_[1].x = x2;
	transform_[1].y = y2;
	transform_[2].x = x3;
	transform_[2].y = y3;
	transform_[3].x = x4;
	transform_[3].y = y4;
	upSpeed = 8;
	downSpeed = 3;
	changeTimer[0] = 60.0f;
	changeTimer[1] = 30.0f;
	changeTimer[2] = 0.0f;
	changeTimer[3] = 90.0f;
	isUp_[0] = true;
	isDown_[0] = false;
	isUp_[1] = false;
	isDown_[1] = true;
	isUp_[2] = true;
	isDown_[2] = false;
	isUp_[3] = false;
	isDown_[3] = true;


	count = 0;

	LoadDivGraph("Resources/helicopterGIF.png", 18, 18, 1, 280, 120, GHandle);
}

void Helicopter::Update() {
	for (int i = 0; i < 4; i++)
	{
		changeTimer[i]--;
	}
	count++;
	if (count == 18) {
		count = 0;
	}

#pragma region 1機目
	if (changeTimer[0] < 0 && !isUp_[0])
	{
		isUp_[0] = true;
		isDown_[0] = false;
		changeTimer[0] = 60.0f;
	}
	else if (changeTimer[0] < 0 && !isDown_[0])
	{
		isUp_[0] = false;
		isDown_[0] = true;
		changeTimer[0] = 60.0f;
	}
	if (isUp_[0])
	{
		transform_[0].y -= upSpeed;
	}
	else if (isDown_[0])
	{
		transform_[0].y += downSpeed;
	}
	if (transform_[0].y <= max_ - transform_[0].ry)
	{
		transform_[0].y = max_ - transform_[0].ry;
	}
#pragma endregion

#pragma region 2機目
	if (changeTimer[1] < 0 && !isUp_[1])
	{
		isUp_[1] = true;
		isDown_[1] = false;
		changeTimer[1] = 60.0f;
	}
	else if (changeTimer[1] < 0 && !isDown_[1])
	{
		isUp_[1] = false;
		isDown_[1] = true;
		changeTimer[1] = 60.0f;
	}
	if (isUp_[1])
	{
		transform_[1].y -= upSpeed;
	}
	else if (isDown_[1])
	{
		transform_[1].y += downSpeed;
	}
	if (transform_[1].y <= max_ - transform_[1].ry)
	{
		transform_[1].y = max_ - transform_[1].ry;
	}
#pragma endregion

#pragma region 3機目
	if (changeTimer[2] < 0 && !isUp_[2])
	{
		isUp_[2] = true;
		isDown_[2] = false;
		changeTimer[2] = 60.0f;
	}
	else if (changeTimer[2] < 0 && !isDown_[2])
	{
		isUp_[2] = false;
		isDown_[2] = true;
		changeTimer[2] = 60.0f;
	}
	if (isUp_[2])
	{
		transform_[2].y -= upSpeed;
	}
	else if (isDown_[2])
	{
		transform_[2].y += downSpeed;
	}
	if (transform_[2].y <= max_ - transform_[2].ry)
	{
		transform_[2].y = max_ - transform_[2].ry;
	}
#pragma endregion

#pragma region 4機目
	if (changeTimer[3] < 0 && !isUp_[3])
	{
		isUp_[3] = true;
		isDown_[3] = false;
		changeTimer[3] = 60.0f;
	}
	else if (changeTimer[3] < 0 && !isDown_[3])
	{
		isUp_[3] = false;
		isDown_[3] = true;
		changeTimer[3] = 60.0f;
	}
	if (isUp_[3])
	{
		transform_[3].y -= upSpeed;
	}
	else if (isDown_[3])
	{
		transform_[3].y += downSpeed;
	}
	if (transform_[3].y <= max_ - transform_[3].ry)
	{
		transform_[3].y = max_ - transform_[3].ry;
	}
#pragma endregion
}

void Helicopter::Draw() {
	for (int i = 0; i < _countof(transform_); i++)
	{
		DrawGraph(transform_[i].x - transform_[i].rx, transform_[i].y - transform_[i].ry, GHandle[count], TRUE);
	}
}
