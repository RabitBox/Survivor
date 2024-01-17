#pragma once
#include <type_traits>
#include "Transform2D.h"
#include "Collider2D.h"

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
	template<typename T> void InitColider()
	{
		// コライダー生成
		_colider = new T( this );

		// コリジョンシステムに登録
		/* 未対応 */
	}
};

