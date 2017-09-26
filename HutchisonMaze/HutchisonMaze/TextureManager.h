#pragma once

#include "SDLApp.h"
#include <map>
#include <string>
#include <vector>

struct Sprite
{
	std::string m_szSubTextureID;
	SDL_Rect m_rectDestination;
};

struct SubTexture
{
	std::string m_szTextureID;
	SDL_Rect* m_rectSource;
};

class TextureManager : public Singleton<TextureManager>
{
private:
	std::map<std::string, SDL_Texture*> m_mapTextures;
	std::map<std::string, SubTexture*> m_mapSubTextures;
	std::vector<Sprite*> m_listDrawList;

public:
	TextureManager();
	~TextureManager();

	SDL_Texture* LoadTexture(std::string in_texturePath);
	void LoadAtlas(std::string in_texturePath);

	inline SubTexture* GetSubTexture(std::string in_subTextureID) { return m_mapSubTextures[in_subTextureID]; }
	inline SDL_Texture* GetTexture(std::string in_textureID) { return m_mapTextures[in_textureID]; }

	void AddSubTexture(std::string in_subTextureID, std::string in_textureID, SDL_Rect* in_uvs);

	void AddToDrawList(std::string in_subTextureID, SDL_Rect in_spritePos);
	void Render();
};
