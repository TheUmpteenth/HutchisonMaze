#pragma once
#ifndef __DAVIES_SPRITE_COMPONENT_HEADER__
#define __DAVIES_SPRITE_COMPONENT_HEADER__

#include "TransformComponent.h"
#include "Component.h"
#include "SDL_image.h"

class SpriteComponent : public Component
{
private:
	SDL_Texture* m_pTexture;
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