#include "stdafx.h"
#include "Player.h"
#include "Collider2D.h"
#include "PhysicsSystem.h"

Player::Player()
{
	// 初期座標設定
	auto size = Scene::Center();
	Transform.SetPosition( size.x, size.y );
	Transform.SetSize( 70.0f );

	// パラメータ初期化
	_moveSpeed = 100.f;

	// コライダー初期化
	InitColider<CircleCollider>( Collider2D::Tag::PLAYER );
	_collider->SetCallback(std::bind(&Player::HitCallback, &(*this), std::placeholders::_1));
}

Player::~Player()
{
	if (_collider) {
		delete _collider;
	}
}

void Player::OnInitialize() {

}

void Player::OnUpdate() {
	// 移動
	auto speed = _moveSpeed * Scene::DeltaTime();
	if ( KeyA.pressed() ) {
		Transform.Position.X -= ( speed );
	}
	else if ( KeyD.pressed() ) {
		Transform.Position.X += ( speed );
	}

	if ( KeyW.pressed() ) {
		Transform.Position.Y -= ( speed );
	}
	else if ( KeyS.pressed() ) {
		Transform.Position.Y += ( speed );
	}

	// 移動範囲制限
	auto size = Scene::Size();
	Transform.Position.X = std::min(
		std::max(
			Transform.Position.X,
			0.f),
		(float)size.x
	);
	Transform.Position.Y = std::min(
		std::max(
			Transform.Position.Y,
			0.f),
		(float)size.y
	);

	// コリジョン計算対象として登録
	PhysicsSystem::Stack( _collider );
}

void Player::OnDraw()
{
	auto Pos = Transform.Position;
	auto Size = Transform.Size;
	_charImage
		.resized( Size )
		.drawAt(Pos.X, Pos.Y);
}

void Player::OnDestroy()
{
	
}

bool Player::HitCallback(Collider2D* target)
{
	return false;
}
