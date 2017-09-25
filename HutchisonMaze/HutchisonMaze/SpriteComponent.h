#pragma once

#include "TransformComponent.h"
#include "Component.h"
#include "SDL_rect.h"
#include <string>

class SpriteComponent : public Component
{
private:
	std::string m_subTextureID;

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
