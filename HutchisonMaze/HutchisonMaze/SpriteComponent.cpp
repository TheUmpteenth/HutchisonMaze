#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Entity.h"


void SpriteComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	m_subTextureID = "logo";
	m_iHeight = 16;
	m_iWidth = 16;
	m_rectDestination.h = m_iHeight;
	m_rectDestination.w = m_iWidth;
}

void SpriteComponent::Update()
{
	//use a static_cast<> here to avoid letting the compiler choose a reinterpret_cast
	m_rectDestination.x = (int)m_pTransform->m_vPosition.x;
	m_rectDestination.y = (int)m_pTransform->m_vPosition.y;
	m_rectDestination.h = m_iHeight;
	m_rectDestination.w = m_iWidth;
}

void SpriteComponent::Render()
{
	TextureManager::GetInstance()->AddToDrawList(m_subTextureID, m_rectDestination);
}
