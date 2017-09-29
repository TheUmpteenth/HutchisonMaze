#include "Player.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"
#include "CollisionManager.h"
#include "InputHandlingComponent.h"

void Player::Init()
{
	TransformComponent* pTransform = AddComponent<TransformComponent>();
	pTransform->m_vPosition.x = 22.0f;
	pTransform->m_vPosition.y = 22.0f;

	SpriteComponent* sprite = AddComponent<SpriteComponent>();
	sprite->SetSubTexture("logo");
	Vector2D size;
	size.x = 16.0f;
	size.y = 16.0f;
	sprite->SetSize(size);

	m_pInputHandler = AddComponent<InputHandlingComponent>();
	ColliderComponent* collider = AddComponent<ColliderComponent>();
	collider->SetCollisionLayer(COLLISION_LAYER_PLAYER);
}

void Player::OnCollision(const ColliderComponent& in_colliderHit)
{
	TransformComponent* pTransform = GetComponent<TransformComponent>();
	SDL_Rect myAABB = GetComponent<ColliderComponent>()->GetAABB();
	SDL_Rect otherAABB = in_colliderHit.GetAABB();

	float fXDiff = (float)(otherAABB.x - myAABB.x);
	float fYDiff = (float)(otherAABB.y - myAABB.y);

	if (abs(fXDiff) > abs(fYDiff))
	{
		if (fXDiff > 0.0f)
		{
			pTransform->m_vPosition.x = otherAABB.x - ((otherAABB.w + myAABB.w) * 0.5f);
		}
		else
		{
			pTransform->m_vPosition.x = otherAABB.x + ((otherAABB.w + myAABB.w) * 0.5f);
		}
	}
	else
	{
		if (fYDiff > 0.0f)
		{
			pTransform->m_vPosition.y = otherAABB.y - ((otherAABB.h + myAABB.h) * 0.5f);
		}
		else
		{
			pTransform->m_vPosition.y = otherAABB.y + ((otherAABB.h + myAABB.h) * 0.5f);
		}
	}

	m_pInputHandler->SetVelocity(Vector2D::Zero);
}
