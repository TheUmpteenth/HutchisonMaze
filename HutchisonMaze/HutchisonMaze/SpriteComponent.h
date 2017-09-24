#pragma once

#include "TransformComponent.h"
#include "Component.h"
#include "SDL_rect.h"

class SpriteComponent : public Component
{
private:
	const char* m_subTextureID;

	TransformComponent* m_pTransform;
	int m_iWidth;
	int m_iHeight;

	SDL_Rect m_rectDestination;

public:
	void Init();
	void Update();
	void Render();
	void Destroy() {}
};
