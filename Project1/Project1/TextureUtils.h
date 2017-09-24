#pragma once
#ifndef __DAVIES_TEXTURE_UTILS_HEADER__
#define __DAVIES_TEXTURE_UTILS_HEADER__

#include "SDLApp.h"
#include <map>

class TextureUtils
{
private:
	static std::map<char*, SDL_Texture*> m_textureMap;

public:
	static SDL_Texture* LoadTexture(const char* in_texturePath);
};

#endif//__DAVIES_TEXTURE_UTILS_HEADER__