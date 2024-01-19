#pragma once
#include <vector>
#include "Singleton.h"
#include "Collider2D.h"

class PhysicsSystem : public Singleton<PhysicsSystem>
{
	friend class Singleton<PhysicsSystem>;

private:
	std::vector<Collider2D*> _colliderList[ (int)Collider2D::Tag::MAX_TAG ];
	std::vector<Collider2D*> _calcStack;
	std::vector< std::pair<Collider2D*, Collider2D::Tag> > _removeList;

private:
	PhysicsSystem();

	void RemoveFromList();
	void CheckStackAll();
	void HitToAll( Collider2D* collision, Collider2D::Tag tag );

public:
	/// @brief コリジョン処理の実行
	static void Run();

	/// @brief コリジョンの登録
	/// @param collision コリジョン
	/// @param tag 登録しているタグ
	static void Register( Collider2D* collision, Collider2D::Tag tag );

	/// @brief コリジョンの登録解除
	/// @param collision 
	/// @param tag 登録されているタグ
	static void Remove( Collider2D* collision, Collider2D::Tag tag );

	/// @brief 情報が更新されたコリジョンとしてスタックする
	/// @param collision スタックするコリジョン
	static void Stack( Collider2D* collision );

	/// @brief タスクマネージャーの初期化
	static void Create();

	/// @brief タスクマネージャーの解放
	static void Release();
};

