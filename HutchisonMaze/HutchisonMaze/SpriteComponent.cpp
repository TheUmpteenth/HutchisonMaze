#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Entity.h"


void SpriteComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	m_subTextureID = "logo";
	m_iHeight = m_iWidth = 16;
}

void SpriteComponent::Update()
{
	m_rectDestination.x = m_pTransform->x;
	m_rectDestination.y = m_pTransform->y;
	m_rectDestination.h = m_iHeight;
	m_rectDestination.w = m_iWidth;
}

void SpriteComponent::Render()
{
	TextureManager::GetInstance()->AddToDrawList(m_subTextureID, m_rectDestination);
}
