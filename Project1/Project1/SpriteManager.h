#pragma once
#ifndef __DAVIES_SPRITE_MANAGER_HEADER__
#define __DAVIES_SPRITE_MANAGER_HEADER__

#include "Singleton.h"
#include "SDLApp.h"
#include <map>

struct Sprite
{
	SDL_Texture* m_pTexture;
	SDL_Rect m_rectMapping;
};

class SpriteManager : public Singleton<SpriteManager>
{
private:
	std::map<char*, Sprite> m_spriteMap;

public:
	void AddToDrawList(const char* in_sprite, SDL_Rect in_spritePos);
	void Render();
};

#endif//__DAVIES_SPRITE_MANAGER_HEADER__