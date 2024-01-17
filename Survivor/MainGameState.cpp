#include "stdafx.h"
#include "MainGameState.h"

void MainGameState::Enter() {
	_player = new Player();
}

void MainGameState::Update() {

}

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
