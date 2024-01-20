#pragma once
#include <memory>
#include <array>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "SceneStateBase.h"

class MainGameState : public SceneStateBase
{
public:
	/// @brief ゲーム内に存在できる敵の上限
	static const int MAX_ENEMY = 100;

private:
	/// @brief 操作キャラクター
	Player* _player;

	/// @brief 敵
	std::vector<Enemy*> _enemies;

	float _timer;

public:
	explicit MainGameState() : _player(nullptr), _enemies({}), _timer(0.0f){}
	virtual ~MainGameState() {}

public:
	void Enter();
	void Update();
	void Exit();

private:
	void SpawnEnemy();

public:
	void RemoveEnemy( Enemy* enemy );
};

