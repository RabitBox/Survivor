#pragma once
#include <type_traits>
#include "Transform2D.h"
#include "Collider2D.h"
#include "PhysicsSystem.h"

class IGameObject
{
protected:
	/// @brief コリジョン
	Collider2D* _colider = nullptr;

public:
	/// @brief 座標系管理
	Transform2D Transform;

public:
	IGameObject() {}
	virtual ~IGameObject() {}

public:
	template<typename T> void InitColider(Collider2D::Tag tag)
	{
		// コライダー生成
		_colider = new T( this );

		// コリジョンシステムに登録
		PhysicsSystem::Register( _colider, tag );
	}

	virtual bool HitCallback( Collider2D* target ) = 0;
};

