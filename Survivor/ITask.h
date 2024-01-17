#pragma once

class ITask
{
public:
	ITask() {}
	virtual ~ITask() = 0;

public:
	void OnErase();

	virtual void OnInitialize() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDraw() = 0;
	virtual void OnDestroy() = 0;
};

