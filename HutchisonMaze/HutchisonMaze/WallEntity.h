#pragma once

#include "Entity.h"

class WallEntity : public Entity
{
public:
	WallEntity(int in_id) : Entity(in_id) {}

	void Init();
	void Update() {}
	void Render() {}
	void Destroy() {}
	void OnCollision(const ColliderComponent& in_colliderHit) {}
};