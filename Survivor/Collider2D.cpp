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

bool CircleCollider::IsHit(std::shared_ptr<Collider2D> target)
{
	switch ( target->GetType() )
	{
	case Type::CIRCLE: {
		auto self = _owner.lock();
		auto tgt = target->GetOwner().lock();
		auto tgtCollider = std::dynamic_pointer_cast<CircleCollider>(target);
		return IsHitCircle(
			/* posA   = */ self->Transform.Position,
			/* posB	  = */ tgt->Transform.Position,
			/* radius = */ _radius + tgtCollider->GetRadius()
		);
		break;
	}
	default:
		break;
	}
	return false;
}
