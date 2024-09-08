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

	count = 0;

	LoadDivGraph("Resources/helicopterGIF.png", 18, 18, 1, 280, 120, GHandle);
}

void Helicopter::Update() {
	posY -= speedY;
	count++;
	if (count == 18) {
		count = 0;
	}
}

void Helicopter::Draw() {
	//DrawBox(posX - radiusX, posY - radiusY, posX + radiusX, posY + radiusY, GetColor(255, 255, 255), true);
	DrawGraph(posX - radiusX, posY - radiusY, GHandle[count], TRUE);
}
