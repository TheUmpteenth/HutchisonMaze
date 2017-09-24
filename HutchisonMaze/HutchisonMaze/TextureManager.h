#pragma once

#include "SDLApp.h"
#include <map>
#include <vector>

struct Sprite
{
	const char* m_szSubTextureID;
	SDL_Rect m_rectDestination;
};

struct SubTexture
{
	const char* m_szTextureID;
	SDL_Rect* m_rectSource;
};

class TextureManager : public Singleton<TextureManager>
{
private:
	std::map<const char*, SDL_Texture*> m_mapTextures;
	std::map<const char*, SubTexture> m_mapSubTextures;
	std::vector<Sprite*> m_listDrawList;

public:
	TextureManager();

	SDL_Texture* LoadTexture(const char* in_texturePath);

	inline SubTexture GetSubTexture(const char* in_subTextureID) { return m_mapSubTextures[in_subTextureID]; }
	inline SDL_Texture* GetTexture(const char* in_textureID) { return m_mapTextures[in_textureID]; }

	void AddSubTexture(const char* in_subTextureID, const char* in_textureID, SDL_Rect* in_uvs);

	void AddToDrawList(const char* in_subTextureID, SDL_Rect in_spritePos);
	void Render();
};
