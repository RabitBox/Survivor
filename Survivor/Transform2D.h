#pragma once
#include "GameMath.h"

/// @brief トランスフォームクラス
struct Transform2D
{
	Vector2 Position;
	float Size;

	Transform2D() : Position(0.f, 0.f), Size(1.0f){}
	virtual ~Transform2D() {}

	void SetPosition(Vector2 vec) { Position = vec; }
	void SetPosition(int x, int y) { Position.X = x; Position.Y = y; }
	void SetSize(float size) { Size = size; }
};

