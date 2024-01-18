#pragma once
#include "IGameObject.h"
#include "ITask.h"

class Enemy : public IGameObject, public Task::ITask
{
public:
	Enemy();
	virtual ~Enemy() override;

public:
	virtual void OnInitialize() override;
	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnDestroy() override;
};

