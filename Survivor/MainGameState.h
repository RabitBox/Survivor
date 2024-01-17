#pragma once
#include <memory>
#include <array>
#include "Player.h"
#include "Enemy.h"

class MainGameState
{
public:
	/// @brief ゲーム内に存在できる敵の上限
	static const int MAX_ENEMY = 100;

private:
	/// @brief 操作キャラクター
	Player* _player;

	/// @brief 敵
	std::array<Enemy*, MAX_ENEMY> _enemies;


public:
	explicit MainGameState() : _player(nullptr), _enemies({}) {}
	virtual ~MainGameState() {}

public:
	void Enter();
	void Update();
	void Exit();
};

