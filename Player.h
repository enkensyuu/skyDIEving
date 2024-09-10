#pragma once
#include "Transform.h"

class Player
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 挙動
	/// </summary>
	void Move(char* key);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 左の風の当たり判定
	/// </summary>
	void WindowLOnCollision(float y, float ry);

	/// <summary>
	/// 右の風の当たり判定
	/// </summary>
	void WindowROnCollision(float y, float ry);

	/// <summary>
	/// 飛行機の当たり判定
	/// </summary>
	void AirportOnCollision(float x, float rx, float y, float ry);

	/// <summary>
	/// ヘリコプターの当たり判定
	/// </summary>
	void HelicopterOnCollision(float x, float rx, float y, float ry);

	/// <summary>
	/// ゴールの当たり判定
	/// </summary>
	void GoalOnCollision(float x, float rx, float y, float ry);

	const bool isGetDeth() { return isDeth_; }
	const bool isGetGoal() { return isGoal_; }

private:
	Transform transform_;
	float max_ = 1200.0f;
	float min_ = 0.0f;
	float speed_;
	float windowSpeed_;
	bool isDeth_;
	bool isGoal_;
};
