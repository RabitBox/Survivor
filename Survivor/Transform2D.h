#pragma once
#include "GameMath.h"

/// @brief トランスフォームクラス
struct Transform2D
{
	Vector2 Position;

	Transform2D() : Position(0.f, 0.f){}
	virtual ~Transform2D() {}

	void SetPosition(Vector2 vec) { Position = vec; }
};

