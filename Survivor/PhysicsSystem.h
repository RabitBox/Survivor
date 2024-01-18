#pragma once
#include <vector>
#include "Singleton.h"

class PhysicsSystem : public Singleton<PhysicsSystem>
{
	friend class Singleton<PhysicsSystem>;

private:

	PhysicsSystem();

public:
	/// @brief タスクマネージャーの初期化
	static void Create();

	/// @brief タスクマネージャーの解放
	static void Release();
};

