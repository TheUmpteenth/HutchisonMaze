#include "TextureUtils.h"

SDL_Texture* TextureUtils::LoadTexture(const char* in_texturePath)
{
	SDL_Surface* pSurface = IMG_Load(in_texturePath);
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(SDLApp::GetInstance()->GetRenderer(), pSurface);
	SDL_FreeSurface(pSurface);

	return pTexture;
}