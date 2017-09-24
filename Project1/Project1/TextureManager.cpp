#include "TextureManager.h"


TextureManager::TextureManager()
{
	LoadTexture("assets/image.png");
	AddSubTexture("logo", "assets/image.png", NULL);
}

SDL_Texture* TextureManager::LoadTexture(const char* in_texturePath)
{
	if (m_textureMap[in_texturePath] == NULL)
	{
		SDL_Surface* pSurface = IMG_Load(in_texturePath);
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(SDLApp::GetInstance()->GetRenderer(), pSurface);
		SDL_FreeSurface(pSurface);
		m_textureMap[in_texturePath] = pTexture;
	}

	return m_textureMap[in_texturePath];
}

void TextureManager::AddSubTexture(const char* in_subTextureID, const char* in_textureName, SDL_Rect* in_uvs)
{
	SubTexture sub;
	sub.m_textureID = in_textureName;
	sub.m_uvs = in_uvs;
	m_subTextureMap[in_subTextureID] = sub;
}

void TextureManager::AddToDrawList(const char* in_subTextureID, SDL_Rect in_spritePos)
{
	Sprite* newSprite = new Sprite();
	newSprite->m_drawRect = in_spritePos;
	newSprite->m_subTextureID = in_subTextureID;

	SubTexture newSpriteSub = m_subTextureMap[in_subTextureID];

	std::vector<Sprite*>::iterator it = m_drawList.begin();
	for (; it != m_drawList.end(); ++it)
	{
		Sprite* sprite = *it;
		SubTexture sub = m_subTextureMap[in_subTextureID];
		if (newSpriteSub.m_textureID == sub.m_textureID)
		{
			break;
		}
	}

	m_drawList.insert(it, newSprite);
}

void TextureManager::Render()
{
	for (std::vector<Sprite*>::iterator it = m_drawList.begin(); it != m_drawList.end(); ++it)
	{
		Sprite* sprite = *it;
		SubTexture subTexture = GetSubTexture(sprite->m_subTextureID);

		SDL_RenderCopy(SDLApp::GetInstance()->GetRenderer(), GetTexture(subTexture.m_textureID), subTexture.m_uvs, &sprite->m_drawRect);
	}
	m_drawList.clear();
}
