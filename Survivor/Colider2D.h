#pragma once

/// @brief 2Dコライダー基底クラス
class Colider2D : public std::enable_shared_from_this<Colider2D>{
public:
	enum class Type{
		INVALID,
		CIRCLE
	};

private:
	Type _type;

protected:
	Colider2D() : _type(Type::INVALID) {}

public:
	Colider2D(Type type) : _type(type) {}
	virtual ~Colider2D() {}

	Type GetType() { return _type; }
};

/// @brief 2Dコライダー 円
class CircleCollider : public Colider2D {
private:
	//CircleCollider() {}
	CircleCollider(CircleCollider&&) = delete;

public:
	CircleCollider() : Colider2D(Type::CIRCLE) {}
};
