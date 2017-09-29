#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "CollisionManager.h"
#include "Entity.h"

void ColliderComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	SpriteComponent* sprite = m_pParent->GetComponent<SpriteComponent>();
	m_iHeight = sprite->GetDrawRect().h;
	m_iWidth = sprite->GetDrawRect().w;
}

void ColliderComponent::Update() 
{ 
	m_rectCollider.x = m_pTransform->m_vPosition.x;
	m_rectCollider.y = m_pTransform->m_vPosition.y;
	m_rectCollider.w = m_iWidth; 
	m_rectCollider.h = m_iHeight; 
}

void ColliderComponent::ReportCollision(const ColliderComponent &in_colliderHit)
{
	if (m_pParent != NULL)
	{
		m_pParent->OnCollision(in_colliderHit);
	}
}

void ColliderComponent::SetCollisionLayer(CollisionLayer in_eLayer) 
{ 
	m_eLayer = in_eLayer; 
	CollisionManager::GetInstance()->RegisterCollider(*this); 
}
