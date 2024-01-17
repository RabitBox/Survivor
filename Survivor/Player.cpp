#include "stdafx.h"
#include "Player.h"
#include "Collider2D.h"

Player::Player()
{
	InitColider<CircleCollider>();
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
