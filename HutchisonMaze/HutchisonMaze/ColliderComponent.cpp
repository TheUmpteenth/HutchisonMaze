#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "CollisionManager.h"
#include "Entity.h"

void ColliderComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	SpriteComponent* sprite = m_pParent->GetComponent<SpriteComponent>();
	m_vSize.x = (float)sprite->GetDrawRect().w;
	m_vSize.y = (float)sprite->GetDrawRect().h;
}

void ColliderComponent::Update() 
{ 
	m_rectCollider.x = (int)m_pTransform->m_vPosition.x;
	m_rectCollider.y = (int)m_pTransform->m_vPosition.y;
	m_rectCollider.w = (int)m_vSize.x;
	m_rectCollider.h = (int)m_vSize.y;
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
