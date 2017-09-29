#include "WallEntity.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"
#include "CollisionManager.h"

void WallEntity::Init()
{
	AddComponent<TransformComponent>();

	SpriteComponent* sprite = AddComponent<SpriteComponent>();
	sprite->SetSubTexture("wall");
	Vector2D size;
	size.x = 20.0f;
	size.y = 20.0f;
	sprite->SetSize(size);

	AddComponent<ColliderComponent>()->SetCollisionLayer(COLLISION_LAYER_WALL);
}