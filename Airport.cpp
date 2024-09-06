#include <DxLib.h>
#include "Airport.h"

void Airport::Initialize() {
	posX = 100;
	posY = 100;
	radiusX = 70;
	radiusY = 40;
	speed = 5;
}

void Airport::Update() {
	posX += speed;
	if (posX >= 1130) {
		speed = -speed;
	}
	else if(posX <= 70){
		speed = -speed;
	}
}

void Airport::Draw() {
	DrawBox(posX - radiusX, posY - radiusY, posX + radiusX, posY + radiusY, GetColor(255, 255, 255), true);
}
