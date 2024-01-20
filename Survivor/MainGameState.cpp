#include "stdafx.h"
#include "GameMath.h"
#include "MainGameState.h"
#include "PhysicsSystem.h"

#define SPAWN_SPAN 1.0f

/// @brief シーン開始
void MainGameState::Enter() {
	// プレイヤー初期化
	_player = new Player();
	_player->SetScene( this );

	_enemies.reserve( MainGameState::MAX_ENEMY );
}

/// @brief シーン更新
void MainGameState::Update() {
	// 時間加算
	_timer += Scene::DeltaTime();

	// 更新
	{
		// プレイヤー更新
		_player->OnUpdate();

		// 敵更新
		for (auto enemy : _enemies) {
			if (enemy) {
				enemy->OnUpdate();
			}
		}

		// 敵の発生
		SpawnEnemy();
	}

	// 描画
	{
		_player->OnDraw();
		for (auto& enemy : _enemies) {
			if (enemy) {
				enemy->OnDraw();
			}
		}
	}
}

/// @brief シーン終了
void MainGameState::Exit() {
	// 操作キャラを破棄
	delete _player;

	// 敵を破棄
	for ( int i = 0; i < _enemies.size(); ++i ) {
		// nullチェック
		if ( _enemies[i] ) {
			delete _enemies[i];
		}
	}
}

void MainGameState::SpawnEnemy()
{
	if ( _timer < SPAWN_SPAN ) {
		return;
	}
	_timer = 0.0f;

	auto size = Scene::Size();
	Vector2 spawnPosition;
	switch ( Random(3) )
	{
	case 0:	// 上
		spawnPosition.X = Random( size.x );
		break;

	case 1:	// 下
		spawnPosition.X = Random( size.x );
		spawnPosition.Y = size.y;
		break;

	case 2:	// 左
		spawnPosition.Y = Random( size.y );
		break;

	case 3:	// 右
		spawnPosition.Y = Random( size.y );
		spawnPosition.X = size.x;
		break;

	default:
		break;
	}

	if ( _enemies.size() < MainGameState::MAX_ENEMY ) {
		_enemies.push_back( new Enemy() );
		auto obj = _enemies.back();
		obj->Transform.SetPosition(spawnPosition.X, spawnPosition.Y);
		obj->SetTarget( _player );
		obj->SetScene( this );
	}
}

void MainGameState::RemoveEnemy(Enemy* enemy)
{
	auto itr = std::find(_enemies.begin(), _enemies.end(), enemy);
	if ( itr != _enemies.end() ) {
		// (*itr)->OnDestroy();
		delete (*itr);
		_enemies.erase( itr );
	}
}
