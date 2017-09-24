#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "TextureUtils.h"
#include "Entity.h"


void SpriteComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	m_pTexture = TextureUtils::LoadTexture("assets/image.png");
}

void SpriteComponent::Update()
{
	m_rectDestination.x = m_pTransform->x;
	m_rectDestination.y = m_pTransform->y;
	m_rectDestination.h = height;
	m_rectDestination.w = width;
}

void SpriteComponent::Render()
{
	SDL_RenderCopy(SDLApp::GetInstance()->GetRenderer(), m_pTexture, NULL, &m_rectDestination);
}
