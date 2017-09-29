#pragma once
#include "Component.h"
#include <string>
#include <SDL.h>

class TransformComponent;

class SpriteComponent : public Component
{
private:
	std::string m_subTextureID;

	//note c++11 stye init would be 
	//TransformComponent* m_pTransform {nullptr}
	TransformComponent* m_pTransform = NULL;

	int m_iWidth = 0;
	int m_iHeight = 0;

	SDL_Rect m_rectDestination;

public:
	inline SDL_Rect GetDrawRect() const { return m_rectDestination; }
	void Init();
	void Update();
	void Render();
	void Destroy() { m_pTransform = NULL; }
};
