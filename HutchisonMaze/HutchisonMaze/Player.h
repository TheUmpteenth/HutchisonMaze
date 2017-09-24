#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(int in_id) : Entity(in_id) {}

	void Init();
	void Update();
	void Render() {}
	void Destroy() {}
};
