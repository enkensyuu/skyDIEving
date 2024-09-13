#include "Player.h"
#include "Dxlib.h"

void Player::Initialize()
{
	transform_.x = 600.0f;
	transform_.y = 150.0f;
	transform_.rx = 30.0f;
	transform_.ry = 30.0f;
	speed_ = 15.0f;
	windowSpeed_ = 8.0f;
	isDeth_ = false;
	isGoal_ = false;
	Graph = LoadGraph("Resources/player.png");
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

	if (transform_.x >= max_ - transform_.rx)
	{
		transform_.x = max_ - transform_.rx;
	}
	else if (transform_.x <= min_ + transform_.rx)
	{
		transform_.x = min_ + transform_.rx;
	}
}

void Player::Draw()
{
	DrawGraph(transform_.x - transform_.rx, transform_.y - transform_.ry, Graph, true);
}

void Player::WindowLOnCollision(float y, float ry)
{
	if (transform_.y - transform_.ry < y + ry && transform_.y + transform_.ry > y - ry)
	{
		transform_.x -= windowSpeed_;
	}
	if (transform_.x <= min_ + transform_.rx)
	{
		transform_.x = min_ + transform_.rx;
	}
}

void Player::WindowROnCollision(float y, float ry)
{
	if (transform_.y - transform_.ry < y + ry && transform_.y + transform_.ry > y - ry)
	{
		transform_.x += windowSpeed_;
	}
	if (transform_.x >= max_ - transform_.rx)
	{
		transform_.x = max_ - transform_.rx;
	}
}

void Player::AirportOnCollision(float x, float rx, float y, float ry)
{
	if (transform_.x - transform_.rx < x + rx && transform_.x + transform_.rx > x - rx)
	{
		if (transform_.y - transform_.ry  < y + ry && transform_.y + transform_.ry > y - ry)		{
			isDeth_ = true;
		}
	}
}

void Player::HelicopterOnCollision(float x, float rx, float y, float ry)
{
	if (transform_.x - transform_.rx < x + rx && transform_.x + transform_.rx > x - rx)
	{
		if (transform_.y - transform_.ry < y + ry && transform_.y + transform_.ry > y - ry)
		{
			isDeth_ = true;
		}
	}
}

void Player::GoalOnCollision(float y, float ry)
{
	if (transform_.y - transform_.ry < y + ry && transform_.y + transform_.ry > y - ry)
	{
		isGoal_ = true;
	}
}