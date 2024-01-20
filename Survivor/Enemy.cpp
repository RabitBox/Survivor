#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	// 初期化
	_target = nullptr;
	_moveSpeed = 80.f;

	// コライダー初期化
	InitColider<CircleCollider>( Collider2D::Tag::ENEMY );
}

Enemy::~Enemy()
{
	if (_colider) {
		delete _colider;
	}
}

void Enemy::OnInitialize() {

}

void Enemy::OnUpdate() {
	if ( _target ) {
		// ターゲット方向へのベクトルを取得
		auto targetVec = (_target->Transform.Position - Transform.Position);
		targetVec.Normalize();
		// 常にターゲット方向へ進行する
		Transform.Position += (targetVec * _moveSpeed);
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
	
}

bool Enemy::HitCallback(Collider2D* target)
{
	return false;
}
