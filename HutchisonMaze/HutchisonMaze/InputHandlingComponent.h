#pragma once
#include "Component.h"
#include "Vector2D.h"

class TransformComponent;

class InputHandlingComponent : public Component
{
private:
	//note c++11 stye init would be 
	//TransformComponent* m_pTransform {nullptr}
	TransformComponent* m_pTransform = 0;
	float m_fSpeed = 0.0f;
	Vector2D m_vVelocity = Vector2D::Zero;

public:
	void Init();
	void Destroy() { m_pTransform = 0; }
	void Update();
	void Render() {}
	inline Vector2D GetVelocity() const { return m_vVelocity; }
	inline void SetVelocity(const Vector2D& in_velocity) { m_vVelocity = in_velocity; }
};