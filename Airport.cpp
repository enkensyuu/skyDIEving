#include <DxLib.h>
#include "Airport.h"

void Airport::Initialize() {
	posX = 1000;
	posY = 1000;
	radiusX = 140;
	radiusY = 60;
	speedX = 5;
	speedY = 1;
}

void Airport::Update() {
	posX += speedX;
	if (posX >= 1400) {
		speedX = -speedX;
	}
	else if(posX <= -200){
		speedX = -speedX;
	}
	posY -= speedY;
}

void Airport::Draw() {
	DrawBox(posX - radiusX, posY - radiusY, posX + radiusX, posY + radiusY, GetColor(255, 255, 255), true);
}
