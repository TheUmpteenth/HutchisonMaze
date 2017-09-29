#pragma once
#include "Component.h"

class TransformComponent;

class InputHandlingComponent : public Component
{
private:
	//note c++11 stye init would be 
	//TransformComponent* m_pTransform {nullptr}
	TransformComponent* m_pTransform = 0;
	float m_fSpeed = 0.0f;

public:
	void Init();
	void Destroy() { m_pTransform = 0; }
	void Update();
	void Render() {}
	float m_fVelocityX;
	float m_fVelocityY;
};