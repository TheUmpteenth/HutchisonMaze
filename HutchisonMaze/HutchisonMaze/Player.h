#pragma once

#include "Entity.h"

class InputHandlingComponent;

class Player : public Entity
{
private:
	InputHandlingComponent* m_pInputHandler = NULL;
public:
	Player(int in_id) : Entity(in_id) {}

	void Init();
	void Update() {}
	void Render() {}
	void Destroy() {}

	void OnCollision(const ColliderComponent& in_colliderHit);
};
