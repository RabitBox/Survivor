#include "stdafx.h"
#include "Player.h"
#include "Collider2D.h"
#include "TaskManager.h"

Player::Player()
{
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

void Player::OnDraw() {

}

void Player::OnDestroy() {

}
