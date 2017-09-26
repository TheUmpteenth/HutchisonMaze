#include "TextureManager.h"
#include "tinyXML/tinyxml2.h"


TextureManager::TextureManager()
{
	LoadAtlas("assets/atlasTest.xml");
}

TextureManager::~TextureManager()
{
	for (std::vector<Sprite*>::iterator it = m_listDrawList.begin(); it != m_listDrawList.end(); ++it)
	{
		Sprite* sprite = *it;
		delete sprite;
	}
	for (std::map<std::string, SubTexture*>::iterator it = m_mapSubTextures.begin(); it != m_mapSubTextures.end(); ++it)
	{
		SubTexture* sub = it->second;
		delete sub;
	}
	for (std::map<std::string, SDL_Texture*>::iterator it = m_mapTextures.begin(); it != m_mapTextures.end(); ++it)
	{
		SDL_Texture* texture = it->second;
		SDL_DestroyTexture(texture);
	}
}

void TextureManager::LoadAtlas(std::string in_atlasFilePath)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(in_atlasFilePath.c_str());
	tinyxml2::XMLElement* elem = doc.FirstChildElement("Texture");
	std::string texturePath = elem->Attribute("Path");
	LoadTexture(texturePath);
	for (tinyxml2::XMLElement* e = elem->FirstChildElement("Rect"); e != NULL; e = e->NextSiblingElement("Rect"))
	{
		SDL_Rect* destRect = new SDL_Rect();
		e->QueryIntAttribute("x", &destRect->x);
		e->QueryIntAttribute("y", &destRect->y);
		e->QueryIntAttribute("w", &destRect->w);
		e->QueryIntAttribute("h", &destRect->h);
		AddSubTexture(e->Attribute("Name"), texturePath, destRect);
	}
}

SDL_Texture* TextureManager::LoadTexture(std::string in_texturePath)
{
	if (m_mapTextures[in_texturePath] == NULL)
	{
		SDL_Surface* pSurface = IMG_Load(in_texturePath.c_str());
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(SDLApp::GetInstance()->GetRenderer(), pSurface);
		SDL_FreeSurface(pSurface);
		m_mapTextures[in_texturePath] = pTexture;
	}

	return m_mapTextures[in_texturePath];
}

void TextureManager::AddSubTexture(std::string in_subTextureID, std::string in_textureName, SDL_Rect* in_uvs)
{
	SubTexture* sub = new SubTexture();
	sub->m_szTextureID = in_textureName;
	sub->m_rectSource = in_uvs;
	m_mapSubTextures[in_subTextureID] = sub;
}

void TextureManager::AddToDrawList(std::string in_subTextureID, SDL_Rect in_spritePos)
{
	Sprite* newSprite = new Sprite();
	newSprite->m_rectDestination = in_spritePos;
	newSprite->m_szSubTextureID = in_subTextureID;

	SubTexture* newSpriteSub = m_mapSubTextures[in_subTextureID];

	std::vector<Sprite*>::iterator it = m_listDrawList.begin();
	for (; it != m_listDrawList.end(); ++it)
	{
		Sprite* sprite = *it;
		SubTexture* sub = m_mapSubTextures[in_subTextureID];
		if (newSpriteSub->m_szTextureID == sub->m_szTextureID)
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
		SubTexture* subTexture = GetSubTexture(sprite->m_szSubTextureID);

		SDL_RenderCopy(SDLApp::GetInstance()->GetRenderer(), GetTexture(subTexture->m_szTextureID), subTexture->m_rectSource, &sprite->m_rectDestination);
	}
	m_listDrawList.clear();
}
