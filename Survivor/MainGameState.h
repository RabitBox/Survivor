#pragma once
#include<memory>
#include "Player.h"
#include "Enemy.h"

class MainGameState
{
public:
	static const int MAX_ENEMY = 100;

private:
	/// @brief 操作キャラクター
	std::shared_ptr<Player> _player;

	/// @brief 敵
	std::shared_ptr<Enemy> _enemies[MAX_ENEMY];

public:
	explicit MainGameState() {}
	virtual ~MainGameState() {}

public:
	void Start();
	void Update();
	void Exit();
};

