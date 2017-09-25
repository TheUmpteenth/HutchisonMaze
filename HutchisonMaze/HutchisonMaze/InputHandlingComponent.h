#pragma once
#include "Component.h"
#include "TransformComponent.h"

class InputHandlingComponent : public Component
{
private:
	TransformComponent* m_pTransform;
	float m_fSpeed;
	float m_fVelocityX;
	float m_fVelocityY;

public:
	void Init();
	void Destroy() {}
	void Update();
	void Render() {}
};