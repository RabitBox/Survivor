#pragma once
#include "IGameObject.h"
#include "ITask.h"

class Player final : public IGameObject, public Task::ITask
{
public:
	explicit Player();
	virtual ~Player() override;

public:
	virtual void OnInitialize() override;
	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnDestroy() override;
};

