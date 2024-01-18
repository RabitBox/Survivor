#pragma once

/// @brief ベクトル
struct Vector2
{
	union {
		float X;
		float Width;
	};
	union {
		float Y;
		float Height;
	};

	Vector2() { X = 0.f; Y = 0.f; }
	Vector2(float x, float y) { X = x, Y = y; }

	Vector2 operator + (Vector2 vec) {
		X += vec.X;
		Y += vec.Y;
		return *this;
	}

	Vector2 operator += (Vector2 vec) {
		X += vec.X;
		Y += vec.Y;
		return *this;
	}

	Vector2 operator - (Vector2 vec) {
		X -= vec.X;
		Y -= vec.Y;
		return *this;
	}

	Vector2 operator -= (Vector2 vec) {
		X -= vec.X;
		Y -= vec.Y;
		return *this;
	}

	Vector2 operator * (float f) {
		X *= f;
		Y *= f;
		return *this;
	}

	void Normalize() {
		float length = sqrtf(X * X + Y * Y);
		X = X / length;
		Y = Y / length;
	}
};
