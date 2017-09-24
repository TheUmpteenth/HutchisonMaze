#pragma once
#ifndef __DAVIES_TEXTURE_UTILS_HEADER__
#define __DAVIES_TEXTURE_UTILS_HEADER__

#include "SDLApp.h"
#include <map>
#include <vector>

struct Sprite
{
	const char* m_subTextureID;
	SDL_Rect m_drawRect;
};

struct SubTexture
{
	const char* m_textureID;
	SDL_Rect* m_uvs;
};

class TextureManager : public Singleton<TextureManager>
{
private:
	std::map<const char*, SDL_Texture*> m_textureMap;
	std::map<const char*, SubTexture> m_subTextureMap;
	std::vector<Sprite*> m_drawList;

public:
	TextureManager();

	SDL_Texture* LoadTexture(const char* in_texturePath);

	inline SubTexture GetSubTexture(const char* in_subTextureID) { return m_subTextureMap[in_subTextureID]; }
	inline SDL_Texture* GetTexture(const char* in_textureID) { return m_textureMap[in_textureID]; }

	void AddSubTexture(const char* in_subTextureID, const char* in_textureID, SDL_Rect* in_uvs);

	void AddToDrawList(const char* in_subTextureID, SDL_Rect in_spritePos);
	void Render();
};

#endif//__DAVIES_TEXTURE_UTILS_HEADER__