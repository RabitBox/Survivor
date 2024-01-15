#include "stdafx.h"
#include "IGameObject.h"

template<typename T>
void IGameObject::InitColider()
{
	// コライダー生成
	_colider = std::make_shared<T>( std::weak_ptr<IGameObject>( GetPtr() ) );
}
