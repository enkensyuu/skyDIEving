#include <DxLib.h>
#include "Airport.h"

void Airport::Initialize(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {

	for (int i = 0; i < 4; i++)
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
	speedX = 15;
	speedY = 3;
	changeL[0] = true;
	changeR[0] = false;
	changeL[1] = false;
	changeR[1] = true;
	changeL[2] = true;
	changeR[2] = false;
	changeL[3] = false;
	changeR[3] = true;
	GraphL = LoadGraph("Resources/airport.png");
	GraphR = LoadGraph("Resources/airportRight.png");
}

void Airport::Update() {

#pragma region 1機目
	if (transform_[0].x > 1400) {
		changeL[0] = true;
		changeR[0] = false;
	}
	else if (transform_[0].x <= -200) {
		changeL[0] = false;
		changeR[0] = true;
	}

	if (changeL[0])
	{
		transform_[0].x -= speedX;
	}
	else if (changeR[0])
	{
		transform_[0].x += speedX;
	}
#pragma endregion

#pragma region 2機目
	if (transform_[1].x > 1400) {
		changeL[1] = true;
		changeR[1] = false;
	}
	else if (transform_[1].x <= -200) {
		changeL[1] = false;
		changeR[1] = true;
	}

	if (changeL[1])
	{
		transform_[1].x -= speedX;
	}
	else if (changeR[1])
	{
		transform_[1].x += speedX;
	}
#pragma endregion

#pragma region 3機目
	if (transform_[2].x > 1400) {
		changeL[2] = true;
		changeR[2] = false;
	}
	else if (transform_[2].x <= -200) {
		changeL[2] = false;
		changeR[2] = true;
	}

	if (changeL[2])
	{
		transform_[2].x -= speedX;
	}
	else if (changeR[2])
	{
		transform_[2].x += speedX;
	}
#pragma endregion

#pragma region 4機目
	if (transform_[3].x > 1400) {
		changeL[3] = true;
		changeR[3] = false;
	}
	else if (transform_[3].x <= -200) {
		changeL[3] = false;
		changeR[3] = true;
	}

	if (changeL[3])
	{
		transform_[3].x -= speedX;
	}
	else if (changeR[3])
	{
		transform_[3].x += speedX;
	}
#pragma endregion

	for (int i = 0; i < 4; i++)
	{
		transform_[i].y -= speedY;

		if (transform_[i].y <= max_ - transform_[i].ry)
		{
			transform_[i].y = max_ - transform_[i].ry;
		}
	}
}

void Airport::Draw() {

#pragma region 1機目
	if (changeL[0])
	{
		DrawGraph(transform_[0].x - transform_[0].rx, transform_[0].y - transform_[0].ry, GraphL, true);
	}
	else if (changeR[0])
	{
		DrawGraph(transform_[0].x - transform_[0].rx, transform_[0].y - transform_[0].ry, GraphR, true);
	}
#pragma endregion

#pragma region 2機目
	if (changeL[1])
	{
		DrawGraph(transform_[1].x - transform_[1].rx, transform_[1].y - transform_[1].ry, GraphL, true);
	}
	else if (changeR[1])
	{
		DrawGraph(transform_[1].x - transform_[1].rx, transform_[1].y - transform_[1].ry, GraphR, true);
	}
#pragma endregion

#pragma region 3機目
	if (changeL[2])
	{
		DrawGraph(transform_[2].x - transform_[2].rx, transform_[2].y - transform_[2].ry, GraphL, true);
	}
	else if (changeR[2])
	{
		DrawGraph(transform_[2].x - transform_[2].rx, transform_[2].y - transform_[2].ry, GraphR, true);
	}
#pragma endregion

#pragma region 4機目
	if (changeL[3])
	{
		DrawGraph(transform_[3].x - transform_[3].rx, transform_[3].y - transform_[3].ry, GraphL, true);
	}
	else if (changeR[3])
	{
		DrawGraph(transform_[3].x - transform_[3].rx, transform_[3].y - transform_[3].ry, GraphR, true);
	}
#pragma endregion
}
