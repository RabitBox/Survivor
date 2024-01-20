#include "stdafx.h"
#include "Collider2D.h"
#include "GameMath.h"
#include "IGameObject.h"

/// @brief 円どうしの衝突判定
/// @param posA 判定する円の座標A
/// @param posB 判定する円の座標B
/// @param radius 判定する円の合計半径
/// @return 衝突していれば true
bool IsHitCircle(const Vector2& posA, const Vector2& posB, float radius) {
	auto x = posA.X - posB.X;
	auto y = posA.Y - posB.Y;
	return x * x + y * y < radius * radius;
}

bool CircleCollider::IsHit(Collider2D* target)
{
	switch ( target->GetType() )
	{
	case Type::CIRCLE: {
		auto targetOwner = target->GetOwner();
		return IsHitCircle(
			/* posA   = */ _owner->Transform.Position,
			/* posB	  = */ targetOwner->Transform.Position,
			/* radius = */ _owner->Transform.GetRadius() + targetOwner->Transform.GetRadius()
		);
	} break;

	default: {

	}break;
	}
	return false;
}
