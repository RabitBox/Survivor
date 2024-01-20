#include "stdafx.h"
#include "Enemy.h"
#include "MainGameState.h"

Enemy::Enemy()
{
	// 初期化
	_target = nullptr;
	_moveSpeed = 80.f;
	Transform.SetSize( 90.0f );

	// コライダー初期化
	InitColider<CircleCollider>( Collider2D::Tag::ENEMY );

	_collider->SetCallback( std::bind(&Enemy::HitCallback, &(*this), std::placeholders::_1) );
	// _collider->SetCallback( [this](Collider2D* obj) { return this->HitCallback(obj); });
}

Enemy::~Enemy()
{
	if (_collider) {
		delete _collider;
		_collider = nullptr;
	}
}

void Enemy::OnInitialize() {

}

void Enemy::OnUpdate() {
	if ( _target ) {
		// ターゲット方向へのベクトルを取得
		auto targetVec = _target->Transform.Position;
		targetVec -= Transform.Position;
		targetVec.Normalize();

		// 常にターゲット方向へ進行する
		auto moveSpeed = _moveSpeed * Scene::DeltaTime();
		Transform.Position += (targetVec * moveSpeed);
	}
}

void Enemy::OnDraw() {
	auto Pos = Transform.Position;
	auto Size = Transform.Size;
	_charImage
		.resized(Size)
		.drawAt(Pos.X, Pos.Y);
}

void Enemy::OnDestroy() {
	PhysicsSystem::Remove(_collider, Collider2D::Tag::ENEMY );
}

bool Enemy::HitCallback(Collider2D* target)
{
	auto owner = static_cast<MainGameState*>(_ownerScene);
	if (owner) {
		owner->RemoveEnemy( this );
		return true;
	}
	return false;
}
