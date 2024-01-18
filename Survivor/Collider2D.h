#pragma once

class IGameObject;

/// @brief 2Dコライダー基底クラス
class Collider2D{
public:
	enum class Type{
		INVALID,
		CIRCLE
	};

private:
	Type _type;

protected:
	IGameObject* _owner;

protected:
	Collider2D() : _type(Type::INVALID), _owner(nullptr) {}

public:
	Collider2D(Type type, IGameObject* owner) : _type(type), _owner(owner) {}
	virtual ~Collider2D() {}

	Type GetType() const { return _type; }
	IGameObject* GetOwner() const { return _owner; }

	virtual bool IsHit(Collider2D* target) = 0;
};

/// @brief 2Dコライダー 円
class CircleCollider final : public Collider2D {
private:
	CircleCollider() {}
	CircleCollider(CircleCollider&&) = delete;

public:
	CircleCollider(IGameObject* owner) : Collider2D(Type::CIRCLE, owner) {}

	bool IsHit(Collider2D* target) override;
};
