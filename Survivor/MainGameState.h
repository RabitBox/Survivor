#pragma once
#include<memory>

class MainGameState
{
public:
	const int MAX_ENEMY = 256;

private:
	/// @brief 操作キャラクター
	//std::shared_ptr<> _player;

	/// @brief 敵
	//std::shared_ptr<> _enemies[MAX_ENEMY];

public:
	explicit MainGameState() {}
	virtual ~MainGameState() {}

public:
	void Start();
	void Update();
	void Exit();
};

