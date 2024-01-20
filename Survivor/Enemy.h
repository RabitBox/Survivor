#pragma once
#include "IGameObject.h"
#include "ITask.h"

class Enemy : public IGameObject, public Task::ITask
{
private:
	IGameObject* _target;

	Texture _charImage{ U"🐈"_emoji };
	float _moveSpeed;

public:
	Enemy();
	virtual ~Enemy() override;

public:
	virtual void OnInitialize() override;
	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnDestroy() override;

	virtual bool HitCallback(Collider2D* target) override;

public:
	/// @brief 攻撃対象をセットする
	/// @param target 攻撃対象
	virtual void SetTarget(IGameObject* target) { _target = target; }
};

