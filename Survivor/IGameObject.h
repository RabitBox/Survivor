#pragma once
#include <type_traits>
#include "Transform2D.h"
#include "Collider2D.h"
#include "PhysicsSystem.h"

class SceneStateBase;

class IGameObject
{
protected:
	/// @brief コリジョン
	Collider2D* _collider = nullptr;

	/// @brief 所属しているシーン
	SceneStateBase* _ownerScene = nullptr;

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
		_collider = new T( this );
		_collider->SetTag( tag );

		// コリジョンシステムに登録
		PhysicsSystem::Register(_collider, tag );
	}

	virtual bool HitCallback( Collider2D* target ) = 0;

	void SetScene( SceneStateBase* scene ) { _ownerScene = scene; }
};

