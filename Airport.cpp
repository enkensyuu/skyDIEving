#include <DxLib.h>
#include "Airport.h"

void Airport::Initialize(float x, float y) {
	transform_.x = x;
	transform_.y = y;
	transform_.rx = 140;
	transform_.ry = 60;
	speedX = 15;
	speedY = 3;
}

void Airport::Update() {
	transform_.x += speedX;
	if (transform_.x >= 1400) {
		speedX = -speedX;
	}
	else if(transform_.x <= -200){
		speedX = -speedX;
	}
	transform_.y -= speedY;
}

void Airport::Draw() {
	DrawBox(transform_.x - transform_.rx, transform_.y - transform_.ry, transform_.x + transform_.rx, transform_.y + transform_.ry, GetColor(255, 255, 255), true);
}
