#include "stdafx.h"
#include "Player.h"
#include "Collider2D.h"
#include "PhysicsSystem.h"

Player::Player()
{
	// 初期座標設定
	auto size = Scene::Center();
	Transform.SetPosition( size.x, size.y );
	Transform.SetSize( 100.0f );

	// パラメータ初期化
	_moveSpeed = 100.f;

	// コライダー初期化
	InitColider<CircleCollider>( Collider2D::Tag::PLAYER );
}

Player::~Player()
{
	if ( _colider ) {
		delete _colider;
	}
}

void Player::OnInitialize() {

}

void Player::OnUpdate() {
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

	PhysicsSystem::Stack( _colider );
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
