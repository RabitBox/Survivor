#pragma once

class IGameObject;

/// @brief 2Dコライダー基底クラス
class Collider2D : public std::enable_shared_from_this<Collider2D>{
public:
	enum class Type{
		INVALID,
		CIRCLE
	};

private:
	Type _type;

protected:
	std::weak_ptr<IGameObject> _owner;

protected:
	Collider2D() : _type(Type::INVALID) {}

public:
	Collider2D(Type type, std::weak_ptr<IGameObject> owner) : _type(type), _owner(owner) {}
	virtual ~Collider2D() {}

	Type GetType() { return _type; }
	std::weak_ptr<IGameObject> GetOwner() { return _owner; }

	virtual bool IsHit(std::shared_ptr<Collider2D> target) = 0;
};

/// @brief 2Dコライダー 円
class CircleCollider final : public Collider2D {
private:
	CircleCollider() : _radius(1.f) {}
	CircleCollider(CircleCollider&&) = delete;

	float _radius;

public:
	CircleCollider(std::weak_ptr<IGameObject> owner) : Collider2D(Type::CIRCLE, owner), _radius(1.f) {}

	bool IsHit(std::shared_ptr<Collider2D> target);

public:
	void SetRadius(float radius) { _radius = radius; }
	float GetRadius() { return _radius; }
};
