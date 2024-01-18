#include "stdafx.h"
#include "MainGameState.h"

/// @brief シーン開始
void MainGameState::Enter() {
	// プレイヤー初期化
	_player = new Player();
}

/// @brief シーン更新
void MainGameState::Update() {

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
