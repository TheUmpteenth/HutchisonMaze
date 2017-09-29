#pragma once
#include "Component.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D m_vPosition;

	void Init()
	{
		m_vPosition.x = 0;
		m_vPosition.y = 0;
	}

	void Destroy() {}
	void Update() {}
	void Render() {}
};
