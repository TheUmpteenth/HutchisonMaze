#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Entity.h"

void SpriteComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
}

void SpriteComponent::Update()
{
	//use a static_cast<> here to avoid letting the compiler choose a reinterpret_cast
	m_rectDestination.x = (int)m_pTransform->m_vPosition.x;
	m_rectDestination.y = (int)m_pTransform->m_vPosition.y;
	m_rectDestination.w = (int)m_vSize.x;
	m_rectDestination.h = (int)m_vSize.y;
}

void SpriteComponent::Render()
{
	TextureManager::GetInstance()->AddToDrawList(m_subTextureID, m_rectDestination);
}

void SpriteComponent::SetSize(const Vector2D& in_vSize) 
{ 
	m_vSize = in_vSize;
	m_rectDestination.w = (int)m_vSize.x;
	m_rectDestination.h = (int)m_vSize.y;
}
