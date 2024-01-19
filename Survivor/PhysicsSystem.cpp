#include "stdafx.h"
#include "PhysicsSystem.h"

#pragma region シングルトン実装
static std::unique_ptr<PhysicsSystem> instance;

PhysicsSystem* GetInstance()
{
	return instance.get();
}
#pragma endregion

#pragma region 内部処理
/// @brief _removeListに登録されているコライダーを取り除く
void PhysicsSystem::RemoveFromList()
{
	for (auto itr = _removeList.begin(); itr != _removeList.end(); ++itr) {
		auto& refList(_colliderList[(int)itr->second]);
		auto removeItr = std::remove(refList.begin(), refList.end(), itr->first);
		refList.erase(removeItr, refList.end());
	}
}

/// @brief 計算の対象となるものを調べ、HitToAllに投げる
void PhysicsSystem::CheckStackAll()
{
	for (auto itr = _calcStack.begin(); itr != _calcStack.end(); itr++) {
		auto tag = (*itr)->GetTag();
		switch ( tag )
		{
		case Collider2D::Tag::PLAYER: {

		}break;

		case Collider2D::Tag::ENEMY: {

		}break;

		case Collider2D::Tag::BULLET: {

		}break;
		}
	}
	_calcStack.clear();
}

/// @brief 衝突検知
/// @param collision 検知の主体
/// @param tag 検知したいコリジョンのタグ
void PhysicsSystem::HitToAll(Collider2D* collision, Collider2D::Tag tag)
{
	auto refList( _colliderList[(int)tag] );
	for (auto itr = refList.begin(); itr != refList.end(); ++itr) {
		if ( collision->IsHit( *itr ) ) {
			// 相互にヒット時のコールバックを送る
		}
	}
}
#pragma endregion

PhysicsSystem::PhysicsSystem() {
	_calcStack.reserve( 30 );
}

void PhysicsSystem::Run()
{	
	// 不要なコライダーを削除
	GetInstance()->RemoveFromList();

	// 衝突を検知する
	GetInstance()->CheckStackAll();
}

void PhysicsSystem::Register(Collider2D* collision, Collider2D::Tag tag)
{
	GetInstance()->_colliderList[(int)tag].push_back(collision);
}

void PhysicsSystem::Remove(Collider2D* collision, Collider2D::Tag tag)
{
	GetInstance()->_removeList.push_back(std::pair<Collider2D*, Collider2D::Tag>(collision, tag));
}

void PhysicsSystem::Stack(Collider2D* collision)
{
	GetInstance()->_calcStack.push_back( collision );
}

void PhysicsSystem::Create()
{
	if (instance == nullptr)
	{
		instance = std::unique_ptr<PhysicsSystem>(new PhysicsSystem());
	}
}

void PhysicsSystem::Release()
{
	instance.release();
}
