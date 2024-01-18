#include "stdafx.h"
#include "Player.h"
#include "Collider2D.h"
#include "TaskManager.h"

Player::Player()
{
	// 初期座標設定
	auto size = Scene::Size() / 2;
	Transform.SetPosition( size.x, size.y );
	Transform.SetSize( 100.0f );

	// コライダー初期化
	InitColider<CircleCollider>();

	// タスクシステムへ登録
	Task::TaskManager::Register( this, Task::LEVEL_1 );
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
