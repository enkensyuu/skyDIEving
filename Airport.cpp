#include <DxLib.h>
#include "Airport.h"

void Airport::Initialize() {
	posX = 0;
	posY = 0;
	radiusX = 70;
	radiusY = 40;
}

void Airport::Update() {
	if (posX >= 1200) {
		posX--;
	}
	if (posX <= 1200) {
		posX++;
	}
}

void Airport::Draw() {
	DrawBox(posX - radiusX, posY - radiusY, posX + radiusX, posY + radiusY, GetColor(255, 255, 255), true);
}
