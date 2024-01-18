#include "stdafx.h"
#include "PhysicsSystem.h"

#pragma region シングルトン実装
static std::unique_ptr<PhysicsSystem> instance;

PhysicsSystem* GetInstance()
{
	return instance.get();
}
#pragma endregion

PhysicsSystem::PhysicsSystem() {

}

void PhysicsSystem::Create()
{
	if (instance == nullptr)
	{
		instance = std::unique_ptr<PhysicsSystem>(new PhysicsSystem());
	}
}

void PhysicsSystem::Release()
{
	instance.release();
}
