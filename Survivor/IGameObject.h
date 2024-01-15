#pragma once
#include "Transform2D.h"
#include "Collider2D.h"

class IGameObject : public std::enable_shared_from_this<IGameObject>
{
protected:
	/// @brief コリジョン
	std::shared_ptr<Collider2D> _colider;

public:
	/// @brief 座標系管理
	Transform2D Transform;

public:
	IGameObject() {}
	virtual ~IGameObject() {}

public:
	template<typename T> void InitColider();

protected:
	std::shared_ptr<IGameObject> GetPtr() { return shared_from_this(); }
};

