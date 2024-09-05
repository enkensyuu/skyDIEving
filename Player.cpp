#include "Player.h"
#include "Dxlib.h"

void Player::Initialize()
{
	transform_.x = 600.0f;
	transform_.y = 150.0f;
	transform_.r = 30.0f;
	speed_ = 15.0f;
}

void Player::Move(char* key)
{
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_A] == 1)
	{
		transform_.x -= speed_;
	}
	else if (key[KEY_INPUT_RIGHT] == 1 || key[KEY_INPUT_D] == 1)
	{
		transform_.x += speed_;
	}

	if (transform_.x >= max_ - transform_.r)
	{
		transform_.x = max_ - transform_.r;
	}
	else if (transform_.x <= min_ + transform_.r)
	{
		transform_.x = min_ + transform_.r;
	}
}

void Player::Draw()
{
	DrawBox(transform_.x - transform_.r, transform_.y - transform_.r, transform_.x + transform_.r, transform_.y + transform_.r, GetColor(255, 0, 0), true);
}
