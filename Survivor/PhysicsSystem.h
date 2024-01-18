#pragma once
#include <vector>
#include "Singleton.h"

class PhysicsSystem : public Singleton<PhysicsSystem>
{
	friend class Singleton<PhysicsSystem>;

private:

	PhysicsSystem();
};

