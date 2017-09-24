#pragma once
#ifndef __DAVIES_SPRITE_COMPONENT_HEADER__
#define __DAVIES_SPRITE_COMPONENT_HEADER__

#include "TransformComponent.h"
#include "Component.h"
#include "SDL_rect.h"

class SpriteComponent : public Component
{
private:
	const char* m_subTextureID;

	TransformComponent* m_pTransform;
	int width;
	int height;

	SDL_Rect m_rectDestination;

public:
	void Init();
	void Update();
	void Render();
};

#endif//__DAVIES_SPRITE_COMPONENT_HEADER__