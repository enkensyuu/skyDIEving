#include "Dxlib.h"
#include "helicopter.h"

void Helicopter::Initialize() {
	posX = 1000;
	posY = 1000;
	radiusX = 140;
	radiusY = 60;
	speedX = 5;
	speedY = 3;
	changeTimer = 0.0f;
}

void Helicopter::Update() {
	posY -= speedY;
}

void Helicopter::Draw() {
	DrawBox(posX - radiusX, posY - radiusY, posX + radiusX, posY + radiusY, GetColor(255, 255, 255), true);
}
