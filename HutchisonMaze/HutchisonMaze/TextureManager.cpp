#include "TextureManager.h"


TextureManager::TextureManager()
{
	LoadTexture("assets/image.png");
	AddSubTexture("logo", "assets/image.png", NULL);
}

SDL_Texture* TextureManager::LoadTexture(const char* in_texturePath)
{
	if (m_mapTextures[in_texturePath] == NULL)
	{
		SDL_Surface* pSurface = IMG_Load(in_texturePath);
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(SDLApp::GetInstance()->GetRenderer(), pSurface);
		SDL_FreeSurface(pSurface);
		m_mapTextures[in_texturePath] = pTexture;
	}

	return m_mapTextures[in_texturePath];
}

void TextureManager::AddSubTexture(const char* in_subTextureID, const char* in_textureName, SDL_Rect* in_uvs)
{
	SubTexture sub;
	sub.m_szTextureID = in_textureName;
	sub.m_rectSource = in_uvs;
	m_mapSubTextures[in_subTextureID] = sub;
}

void TextureManager::AddToDrawList(const char* in_subTextureID, SDL_Rect in_spritePos)
{
	Sprite* newSprite = new Sprite();
	newSprite->m_rectDestination = in_spritePos;
	newSprite->m_szSubTextureID = in_subTextureID;

	SubTexture newSpriteSub = m_mapSubTextures[in_subTextureID];

	std::vector<Sprite*>::iterator it = m_listDrawList.begin();
	for (; it != m_listDrawList.end(); ++it)
	{
		Sprite* sprite = *it;
		SubTexture sub = m_mapSubTextures[in_subTextureID];
		if (newSpriteSub.m_szTextureID == sub.m_szTextureID)
		{
			break;
		}
	}

	m_listDrawList.insert(it, newSprite);
}

void TextureManager::Render()
{
	for (std::vector<Sprite*>::iterator it = m_listDrawList.begin(); it != m_listDrawList.end(); ++it)
	{
		Sprite* sprite = *it;
		SubTexture subTexture = GetSubTexture(sprite->m_szSubTextureID);

		SDL_RenderCopy(SDLApp::GetInstance()->GetRenderer(), GetTexture(subTexture.m_szTextureID), subTexture.m_rectSource, &sprite->m_rectDestination);
	}
	m_listDrawList.clear();
}
